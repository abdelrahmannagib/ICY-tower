#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<time.h>
#include<stdlib.h>
#include <iostream>
#include "Menu.h"
using namespace std;
using namespace sf;
struct game
{
    int maxstep, step_pos_on_y, max_session, player_y, player_x, steps_y, steps_x, score_counter, groundheight;
    int random_numbers[900];
    double move_on_y_axis = 0;
    float movespeed = 0.5, jumpspeed = 1.85;
}icy = { 0,600,0,200,NULL,NULL,NULL,0,460 };

#pragma region global initialize
bool moved = false;
bool soundOn = true;
bool musicOn = true;
bool reach_level_of_moving_steps = false;
bool onstep = true;
bool gamestarted = false;
//
//int maxstep = 0;
//int step_pos_on_y = 600;
//int max_session = 0;
//int player_y = 200, player_x, steps_y, steps_x, score_counter = 0;
//double move_on_y_axis = 0;
//int groundheight = 460;
//float movespeed = 0.5, jumpspeed = 1.85;
//
const float gravity = 0.019;

Vector2f velocity(Vector2f(0, 0));

int generate(int);

void CreditsFun();
Credits credits(800, 600);

void HowToPlayFun();
HowtoPlay howtoplay(800, 600);

soundOptions sound(800, 600);
int pageNumber;

#pragma endregion
int main()
{
    while (true)
    {


#pragma region intialize
        sf::RenderWindow window(sf::VideoMode(800, 600), "icy tower", sf::Style::Close);
        Menu menu(800, 600);
        sf::SoundBuffer buffer1, buffer2, buffer3, buffer4;
        buffer1.loadFromFile("jump.wav");
        buffer2.loadFromFile("menusound.wav");
        buffer3.loadFromFile("choosing.wav");
        buffer4.loadFromFile("start.wav");

        sf::Sound sound1, sound2, sound3, sound4;

        sound1.setBuffer(buffer1);
        sound2.setBuffer(buffer2);
        sound3.setBuffer(buffer3);
        sound4.setBuffer(buffer4);

        Music music;

        if (!music.openFromFile("music.ogg"))
            return -1; // error
        music.play();
        music.setLoop(true);

        if (soundOn == false)
        {
            sound1.setVolume(0);
            sound2.setVolume(0);
            sound3.setVolume(0);
            sound4.setVolume(0);

        }
        else
        {
            sound1.setVolume(100);
            sound2.setVolume(100);
            sound3.setVolume(100);
            sound4.setVolume(100);
        }

        if (musicOn == false)
        {
            music.setVolume(0);
        }
        else
        {
            music.setVolume(100);
        }





        Texture idle, idle2;
        idle.loadFromFile("idle (1).png");
        idle2.loadFromFile("idle (1).png");
        RectangleShape idleBack(sf::Vector2f(120, 120));
        idleBack.setTexture(&idle);
        idleBack.setPosition(170, 40);
        RectangleShape idleBack2(sf::Vector2f(120, 120));
        idleBack2.setTexture(&idle2);
        idleBack2.setPosition(598, 40);
        idleBack2.setScale(-1, 1);




        Texture background;
        Sprite walls;
        background.loadFromFile("realbackground.jpg");
        background.setRepeated(true);
        walls.setTexture(background);
        walls.setTextureRect(IntRect(0, 0, 800, 800));


#pragma endregion


        while (window.isOpen())
        {





            sf::Event event;
            while (window.pollEvent(event))
            {

#pragma region key menu



                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        menu.moveUp();
                        sound2.play();
                        break;
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        menu.moveDown();
                        sound2.play();
                        break;
                    }
                }
#pragma endregion
#pragma region choose menu
                //choose Page
                if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Enter)
                {
                    sound3.play();
                    if (menu.mainMenuPressed() == 0) // play
                    {
                        window.close();
                        pageNumber = 0;

                    }
                    if (menu.mainMenuPressed() == 1) // how to play
                    {
                        window.close();
                        pageNumber = 1;
                    }
                    if (menu.mainMenuPressed() == 2) // sound options
                    {
                        window.close();
                        pageNumber = 2;
                    }
                    if (menu.mainMenuPressed() == 3) // credits
                    {
                        window.close();
                        pageNumber = 3;
                    }
                    if (menu.mainMenuPressed() == 4) // exit
                    {
                        window.close();
                        pageNumber = 4;
                    }
                }
#pragma endregion

            }
            window.clear();
            window.draw(walls);
            window.draw(idleBack);
            window.draw(idleBack2);
            menu.draw(window);
            window.display();

        }

        //play

        if (pageNumber == 0)
        {
            RenderWindow window(VideoMode(800, 600), "ICY TOWER", sf::Style::Close);
            sound4.play();
#pragma region texture and sprites
            Texture textuer_player[15], player_idle_texture, step, background, player2, gameover, first_step_tex;
            textuer_player[0].loadFromFile("Run (1).PNG");
            textuer_player[1].loadFromFile("Run (2).PNG");
            textuer_player[2].loadFromFile("Run (3).PNG");
            textuer_player[3].loadFromFile("Run (4).PNG");
            textuer_player[4].loadFromFile("Run (5).PNG");
            textuer_player[5].loadFromFile("Run (6).PNG");
            textuer_player[6].loadFromFile("Run (7).PNG");
            textuer_player[7].loadFromFile("Run (8).PNG");
            textuer_player[8].loadFromFile("Run (9).PNG");
            textuer_player[9].loadFromFile("Run (10).PNG");
            textuer_player[10].loadFromFile("Run (11).PNG");
            textuer_player[11].loadFromFile("Run (12).PNG");
            textuer_player[12].loadFromFile("Run (13).PNG");
            textuer_player[13].loadFromFile("Run (14).PNG");
            textuer_player[14].loadFromFile("Run (15).PNG");
            player_idle_texture.loadFromFile("Idle (1).png");
            background.loadFromFile("realbackground.jpg");
            step.loadFromFile("18.png");
            player2.loadFromFile("Idle (1).png");
            first_step_tex.loadFromFile("first step.png");
            int counter = 0;
            Sprite player_chracter, steps[800], Walls, gameoversprite, firststep;
            gameover.loadFromFile("—Pngtree—creative hand drawn game over_5447059.png");
            gameoversprite.setTexture(gameover);
            gameoversprite.setPosition(150, 800);
            Walls.setTexture(background);
            firststep.setTexture(first_step_tex);
            firststep.setPosition(-100, 500);
            player_chracter.setTexture(textuer_player[counter]);
            player_chracter.setPosition(100, 460);
            player_chracter.setOrigin(60, 50);
            //for randomize steps
            icy.random_numbers[0] = 150;
            for (int i = 1; i < 800; i++)
            {
                int prevstep = icy.random_numbers[i - 1];
                icy.random_numbers[i] = generate(prevstep);
            }
            for (int i = 0; i < 799; i++)
            {
                steps[i].setTexture(step);
            }
#pragma endregion
#pragma region fonts
            Font fontt;
            if (!fontt.loadFromFile("Donald.otf"))
            {
                cout << "font error" << endl;
            }
            Text score_font, max_score_font, step_font;
            score_font.setFont(fontt);
            score_font.setCharacterSize(25);
            score_font.setFillColor(Color::Cyan);
            max_score_font.setFont(fontt);
            max_score_font.setCharacterSize(25);
            max_score_font.setFillColor(Color::Cyan);
            max_score_font.setPosition(0, 50);
            step_font.setFont(fontt);
            step_font.setCharacterSize(25);
            step_font.setFillColor(Color::Cyan);
            step_font.setPosition(0, 70);

#pragma endregion
#pragma region main loop
            while (window.isOpen())
            {
                Event e;
                while (window.pollEvent(e))
                {
                    switch (e.type)
                    {
                    case Event::Closed:
                        window.close();
                        break;
                    }
                    window.clear();


                }
                // mouse position
                if (e.type == Event::MouseButtonPressed)
                {
                    if (e.mouseButton.button == Mouse::Left)
                    {
                        cout << Mouse::getPosition(window).x << endl;
                        cout << Mouse::getPosition(window).y << endl;


                    }
                }
#pragma endregion
#pragma region keymove
                if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
                {
                    window.close();
                    icy.groundheight = 460;
                    reach_level_of_moving_steps = false;
                    icy.step_pos_on_y = 600;
                    gameoversprite.setPosition(150, 800);
                    player_chracter.setPosition(100, 460);
                    icy.score_counter = 0;
                    icy.move_on_y_axis = 0;
                    icy.maxstep = 0;
                }
                if (Keyboard::isKeyPressed(Keyboard::Key::Right))
                {
                    player_chracter.setScale(1, 1);
                    if (counter < 14)
                    {
                        counter++;
                    }
                    else
                    {
                        counter = 0;
                    }
                    player_chracter.setTexture(textuer_player[counter]);
                    velocity.x = icy.movespeed;
                    if (player_chracter.getPosition().x >= 790)         //mosh hy3dy el 7eta
                    {
                        player_chracter.setScale(1, 1);
                        player_chracter.move(-1, 0);
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::Key::Left))
                {
                    player_chracter.setScale(-1, 1);
                    if (counter < 14)
                    {
                        counter++;
                    }
                    else
                    {
                        counter = 0;
                    }
                    player_chracter.setTexture(textuer_player[counter]);
                    velocity.x = -icy.movespeed;
                    if (player_chracter.getPosition().x <= 10)          //mosh hy3dy el 7eta brdo left
                    {
                        player_chracter.setScale(-1, 1);
                        player_chracter.move(1, 0);
                    }
                }
                else
                {
                    velocity.x = 0;
                }

                if (Keyboard::isKeyPressed(Keyboard::Key::Space))
                {
                    if (onstep)
                    {
                        velocity.y = -icy.jumpspeed;
                        player_chracter.setScale(-1, 1);
                        player_chracter.setTexture(player2);
                        sound1.play();
                    }
                }

                player_chracter.move(velocity.x, velocity.y);

                if (player_chracter.getPosition().y  < icy.groundheight )
                {
                    velocity.y += gravity;
                }

                else
                {
                    player_chracter.setPosition(player_chracter.getPosition().x, icy.groundheight );
                }
#pragma endregion
#pragma region onsteps and score
                icy.player_y = player_chracter.getPosition().y;
                icy.player_x = player_chracter.getPosition().x;

                for (int i = 1; i < 500; i++)
                {
                    int j = i;
                    j *= 10;
                    icy.steps_x = steps[i].getPosition().x;
                    icy.steps_y = steps[i].getPosition().y;
                    if (icy.player_y >= icy.steps_y - 25 && icy.player_y <= icy.steps_y + 1 && icy.player_x >= icy.steps_x - 2 && icy.player_x <= icy.steps_x + 300)
                    {
                        if (i > icy.maxstep)
                        {
                            icy.maxstep = i;
                            icy.maxstep--;

                        }
                        step_font.setString("max step " + to_string(icy.maxstep));
                        velocity.y = 0;
                        // cout << i << endl;
                        if (j > icy.score_counter)
                        {
                            icy.score_counter = j;
                            //  score_counter--;

                            cout << icy.score_counter << endl;
                            icy.score_counter -= 10;
                        }
                    }

                }
                score_font.setString("score " + to_string(icy.score_counter));

                if (velocity.y == 0 || icy.player_y == icy.groundheight)
                {
                    onstep = true;

                }
                else if (icy.player_y == 459 && reach_level_of_moving_steps == false)
                {
                    onstep = true;
                }
                else
                {
                    onstep = false;
                }
#pragma endregion
#pragma region player position to make stepsmove
                if (icy.player_y <= 200)
                {
                    reach_level_of_moving_steps = true;
                }
                if (reach_level_of_moving_steps)

                {
                    if (icy.player_y <= 200&&icy.player_y>=0)
                    {
                        icy.move_on_y_axis += 0.3;
                    }
                    else if (icy.player_y < 0)
                    {
                        icy.move_on_y_axis += 1.2;
                        cout << "p_y:  " << icy.player_y << endl;
                    }
                    else
                    {
                        icy.move_on_y_axis += 0.2;
                    }
                    icy.groundheight = 800;

                }
#pragma endregion
#pragma region steps posiotion
                window.clear();
                window.draw(Walls);
                icy.step_pos_on_y = 600;
                for (int i = 0; i < 799; i++)
                {
                    steps[i].setPosition(icy.random_numbers[i], icy.step_pos_on_y + icy.move_on_y_axis);
                    window.draw(steps[i]);
                    icy.step_pos_on_y -= 100;
                }

#pragma endregion
#pragma region display and gameover
                window.draw(player_chracter);
                window.draw(score_font);
                window.draw(step_font);
                //GAME OVERR
                if (icy.player_y >= 640)
                {
                    reach_level_of_moving_steps = false;
                    if (gameoversprite.getPosition().y > 50)
                    {
                        gameoversprite.move(0, -0.4);


                        cout << "pos" << gameoversprite.getPosition().y << endl;

                    }
                    else
                    {
                        gameoversprite.move(0, 0);
                    }
                    window.draw(gameoversprite);
                    player_chracter.setPosition(100, 800);
                    if (icy.score_counter > icy.max_session)
                    {
                        icy.max_session = icy.score_counter;
                    }
                    max_score_font.setString("high score " + to_string(icy.max_session));
                    window.draw(max_score_font);
                }
                if (reach_level_of_moving_steps == false && icy.player_y < 640)
                {
                    window.draw(firststep);
                }
                window.display();

            }
#pragma endregion
        }

        //how to play

        if (pageNumber == 1)
        {
            HowToPlayFun();
        }

        //sound option

        if (pageNumber == 2)
        {
            RenderWindow windowSound(sf::VideoMode(800, 600), "Sound Options", sf::Style::Close);

            Texture background;
            Sprite walls;
            background.loadFromFile("realbackground.jpg");
            background.setRepeated(true);
            walls.setTexture(background);
            walls.setTextureRect(IntRect(0, 0, 800, 800));


            while (windowSound.isOpen())
            {
                Event event;
                if (windowSound.pollEvent(event))
                {
                    if (sf::Keyboard::isKeyPressed(Keyboard::Key::Escape))
                    {
                        windowSound.close();

                    }
                    if (sf::Keyboard::isKeyPressed(Keyboard::Key::Right))
                    {
                        sound2.play();
                        sound.moveright();
                        sound2.play();
                    }
                    if (sf::Keyboard::isKeyPressed(Keyboard::Key::Left))
                    {
                        sound2.play();
                        sound.moveleft();
                        sound2.play();
                    }
                    if (sf::Keyboard::isKeyPressed(Keyboard::Key::Up))
                    {
                        sound2.play();
                        sound.moveup();
                        sound2.play();
                    }
                    if (sf::Keyboard::isKeyPressed(Keyboard::Key::Down))
                    {
                        sound2.play();
                        sound.movedown();
                        sound2.play();
                    }
                    if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Enter)
                    {
                        sound3.play();
                        if (sound.soundOptionsIsPressedcol() == 1 && sound.soundOptionsIsPressedrow() == 0)
                        {
                            cout << soundOn;
                            soundOn = true;
                            sound1.setVolume(100);
                            sound2.setVolume(100);
                            sound3.setVolume(100);
                            sound4.setVolume(100);

                        }
                        if (sound.soundOptionsIsPressedcol() == 2 && sound.soundOptionsIsPressedrow() == 0)
                        {
                            cout << soundOn << endl;
                            soundOn = false;
                            cout << soundOn << endl;

                            sound1.setVolume(0);
                            sound2.setVolume(0);
                            sound3.setVolume(0);
                            sound4.setVolume(0);

                        }
                        if (sound.soundOptionsIsPressedcol() == 1 && sound.soundOptionsIsPressedrow() == 1)
                        {
                            cout << musicOn;
                            musicOn = true;
                            music.setVolume(100);
                        }
                        if (sound.soundOptionsIsPressedrow() == 1 && sound.soundOptionsIsPressedcol() == 2)
                        {
                            cout << musicOn << endl;
                            musicOn = false;
                            cout << musicOn << endl;
                            music.setVolume(0);
                        }

                    }



                }

                windowSound.clear();
                windowSound.draw(walls);
                sound.draw(windowSound);
                windowSound.display();
            }

        }

        //credits

        if (pageNumber == 3)
        {
            CreditsFun();
        }

        //exit

        if (pageNumber == 4)
        {
            break;
        }
    }
    system("pause");
    return 0;
}


void CreditsFun()
{
    RenderWindow windowCredits(sf::VideoMode(800, 600), "Credits", sf::Style::Close);



    Texture background;
    Sprite walls;
    background.loadFromFile("realbackground.jpg");
    background.setRepeated(true);
    walls.setTexture(background);
    walls.setTextureRect(IntRect(0, 0, 800, 800));

    Texture creditB, idle, idle2;
    creditB.loadFromFile("TeamNew.png");
    idle.loadFromFile("idle (1).png");
    idle2.loadFromFile("idle (1).png");
    RectangleShape creditBackground(sf::Vector2f(800, 600));
    creditBackground.setTexture(&creditB);
    creditB.setSmooth(true);
    RectangleShape idleBack(sf::Vector2f(120, 120));
    idleBack.setTexture(&idle);
    idleBack.setPosition(170, 40);
    RectangleShape idleBack2(sf::Vector2f(120, 120));
    idleBack2.setTexture(&idle2);
    idleBack2.setPosition(598, 40);
    idleBack2.setScale(-1, 1);

    while (windowCredits.isOpen())
    {

        Event event;
        while (windowCredits.pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(Keyboard::Key::Escape))
            {
                windowCredits.close();

            }
        }

        windowCredits.clear();
        windowCredits.draw(walls);
        windowCredits.draw(creditBackground);
        windowCredits.draw(idleBack);
        windowCredits.draw(idleBack2);
        credits.Draw(windowCredits);
        windowCredits.display();
    }
}

void HowToPlayFun()
{
    sf::RenderWindow windowHowToPlay(sf::VideoMode(800, 600), "How to Play", sf::Style::Close);

    Texture background, spaceT, leftT, rightT, buttonT;
    Sprite walls, space, left, right, button;
    background.loadFromFile("realbackground.jpg");
    background.setRepeated(true);
    walls.setTexture(background);

    spaceT.loadFromFile("space.png");
    space.setTexture(spaceT);
    space.setPosition(160, 100);
    leftT.loadFromFile("left.png");
    left.setTexture(leftT);
    left.setPosition(10, 252);
    rightT.loadFromFile("right1.png");
    right.setTexture(rightT);
    right.setPosition(630, 250);


    walls.setTextureRect(IntRect(0, 0, 800, 800));


    while (windowHowToPlay.isOpen())
    {
        sf::Event event;
        while (windowHowToPlay.pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(Keyboard::Key::Escape))
            {
                windowHowToPlay.close();

            }


        }




        windowHowToPlay.clear();
        windowHowToPlay.draw(walls);
        windowHowToPlay.draw(space);
        windowHowToPlay.draw(left);
        windowHowToPlay.draw(right);
        howtoplay.DRAW(windowHowToPlay);
        windowHowToPlay.display();

    }
}

int generate(int c)
{
    int newstep;
    bool diffr = true;
    while (diffr == true)
    {

        newstep = rand() % 500;
        int laststep = newstep - c;
        if (laststep <= 180 && laststep >= -180)
        {
            diffr = false;
            break;
        }
        else
        {
            continue;
        }

    }
    return newstep;
}