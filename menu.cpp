#include "Menu.h"
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;



Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("Donald.otf"))
    {
        cout << "Error";
    }
    //Play
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Play");
    mainMenu[0].setOutlineColor(sf::Color::Black);
    mainMenu[0].setOutlineThickness(2);
    mainMenu[0].setCharacterSize(50);
    mainMenu[0].setPosition(sf::Vector2f(20, 200));

    //how to play
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(sf::Color::Color(253, 181, 0));
    mainMenu[1].setString("How To Play");
    mainMenu[1].setOutlineColor(sf::Color::Black);
    mainMenu[1].setOutlineThickness(2);
    mainMenu[1].setCharacterSize(50);
    mainMenu[1].setPosition(sf::Vector2f(20, 280));

    //sound options
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(sf::Color::Color(253, 181, 0));
    mainMenu[2].setString("Sound Options");
    mainMenu[2].setOutlineColor(sf::Color::Black);
    mainMenu[2].setOutlineThickness(2);
    mainMenu[2].setCharacterSize(50);
    mainMenu[2].setPosition(sf::Vector2f(20, 360));

    //credits
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(sf::Color::Color(253, 181, 0));
    mainMenu[3].setString("Credits");
    mainMenu[3].setOutlineColor(sf::Color::Black);
    mainMenu[3].setOutlineThickness(2);
    mainMenu[3].setCharacterSize(50);
    mainMenu[3].setPosition(sf::Vector2f(20, 440));

    //Exit
    mainMenu[4].setFont(font);
    mainMenu[4].setFillColor(sf::Color::Color(253, 181, 0));
    mainMenu[4].setString("Exit");
    mainMenu[4].setOutlineColor(sf::Color::Black);
    mainMenu[4].setOutlineThickness(2);
    mainMenu[4].setCharacterSize(50);
    mainMenu[4].setPosition(sf::Vector2f(20, 520));

    teamName.setFont(font);
    teamName.setFillColor(sf::Color::Color(253, 181, 0));
    teamName.setOutlineColor(sf::Color::Black);
    teamName.setOutlineThickness(10);
    teamName.setString("GEN_177");
    teamName.setCharacterSize(80);
    teamName.setLetterSpacing(2);
    teamName.setPosition(225, 60);
    mainMenuSelected = 0;
}

void Menu::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < 5; i++)
    {
        window.draw(mainMenu[i]);
    }
    window.draw(teamName);
}

void Menu::moveDown()
{
    if (mainMenuSelected + 1 <= Max_main_menu) //check if not on the last item (exit)
    {
        mainMenu[mainMenuSelected].setFillColor(sf::Color::Color(253, 181, 0)); //change the pervious item's color

        mainMenuSelected++;  //move to the lower item
        if (mainMenuSelected == 5)
        {
            mainMenuSelected = 0;
        }
        mainMenu[mainMenuSelected].setFillColor(Color::White);  //change the new item's color

    }
}

void Menu::moveUp()
{
    if (mainMenuSelected - 1 >= -1) //check if not on the first item (play)
    {
        mainMenu[mainMenuSelected].setFillColor(sf::Color::Color(253, 181, 0)); //change the pervious item's color

        mainMenuSelected--;       //move to the upper item
        if (mainMenuSelected == -1)
        {
            mainMenuSelected = 4;
        }
        mainMenu[mainMenuSelected].setFillColor(Color::White);  //Change the new item's color
    }
}

Menu::~Menu()
{


}

/*-----------------------------------------------------------------------*/

HowtoPlay::HowtoPlay(float width, float height)
{

    if (!font.loadFromFile("Donald.otf"))
    {
        cout << "Error";
    }

    HowtoPlayMenu[0].setFont(font);
    HowtoPlayMenu[0].setFillColor(Color::Black);
    HowtoPlayMenu[0].setString("Jump");
    HowtoPlayMenu[0].setCharacterSize(60);
    HowtoPlayMenu[0].setPosition(sf::Vector2f(320, 250));


    HowtoPlayMenu[1].setFont(font);
    HowtoPlayMenu[1].setFillColor(Color::Black);
    HowtoPlayMenu[1].setString("Right");
    HowtoPlayMenu[1].setCharacterSize(52);
    HowtoPlayMenu[1].setPosition(sf::Vector2f(650, 400));



    HowtoPlayMenu[2].setFont(font);
    HowtoPlayMenu[2].setFillColor(Color::Black);
    HowtoPlayMenu[2].setString("Left");
    HowtoPlayMenu[2].setCharacterSize(52);
    HowtoPlayMenu[2].setPosition(sf::Vector2f(40, 400));




    HowtoPlaySelected = 0;
}

void HowtoPlay::DRAW(sf::RenderWindow& windowHowToPlay)
{
    for (int i = 0; i < 3; i++)
    {
        windowHowToPlay.draw(HowtoPlayMenu[i]);
    }
}

HowtoPlay::~HowtoPlay()
{

}

/*------------------------------------------------------------------------*/

soundOptions::soundOptions(float width, float height)
{
    if (!font.loadFromFile("Donald.otf"))
    {
        cout << "Error";
    }


    soundOptionsMenu[0][0].setFont(font);
    soundOptionsMenu[0][0].setFillColor(sf::Color::White);
    soundOptionsMenu[0][0].setString("Sound");
    soundOptionsMenu[0][0].setOutlineColor(sf::Color::Black);
    soundOptionsMenu[0][0].setOutlineThickness(2);
    soundOptionsMenu[0][0].setCharacterSize(50);
    soundOptionsMenu[0][0].setPosition(20, 200);

    soundOptionsMenu[0][1].setFont(font);
    soundOptionsMenu[0][1].setFillColor(sf::Color::Color(253, 181, 0));
    soundOptionsMenu[0][1].setString("ON");
    soundOptionsMenu[0][1].setOutlineColor(sf::Color::Black);
    soundOptionsMenu[0][1].setOutlineThickness(2);
    soundOptionsMenu[0][1].setCharacterSize(50);
    soundOptionsMenu[0][1].setPosition(300, 200);

    soundOptionsMenu[0][2].setFont(font);
    soundOptionsMenu[0][2].setFillColor(sf::Color::Color(253, 181, 0));
    soundOptionsMenu[0][2].setString("OFF");
    soundOptionsMenu[0][2].setOutlineColor(sf::Color::Black);
    soundOptionsMenu[0][2].setOutlineThickness(2);
    soundOptionsMenu[0][2].setCharacterSize(50);
    soundOptionsMenu[0][2].setPosition(500, 200);

    soundOptionsMenu[1][0].setFont(font);
    soundOptionsMenu[1][0].setFillColor(sf::Color::Color(253, 181, 0));
    soundOptionsMenu[1][0].setString("Music");
    soundOptionsMenu[1][0].setOutlineColor(sf::Color::Black);
    soundOptionsMenu[1][0].setOutlineThickness(2);
    soundOptionsMenu[1][0].setCharacterSize(50);
    soundOptionsMenu[1][0].setPosition(20, 350);

    soundOptionsMenu[1][1].setFont(font);
    soundOptionsMenu[1][1].setFillColor(sf::Color::Color(253, 181, 0));
    soundOptionsMenu[1][1].setString("ON");
    soundOptionsMenu[1][1].setOutlineColor(sf::Color::Black);
    soundOptionsMenu[1][1].setOutlineThickness(2);
    soundOptionsMenu[1][1].setCharacterSize(50);
    soundOptionsMenu[1][1].setPosition(300, 350);

    soundOptionsMenu[1][2].setFont(font);
    soundOptionsMenu[1][2].setFillColor(sf::Color::Color(253, 181, 0));
    soundOptionsMenu[1][2].setString("OFF");
    soundOptionsMenu[1][2].setOutlineColor(sf::Color::Black);
    soundOptionsMenu[1][2].setOutlineThickness(2);
    soundOptionsMenu[1][2].setCharacterSize(50);
    soundOptionsMenu[1][2].setPosition(500, 350);




    optionsSelectedrow = 0;
    optionsSelectedcol = 0;
}

void soundOptions::draw(sf::RenderWindow& windowSound)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            windowSound.draw(soundOptionsMenu[i][j]);
        }
    }


}

void soundOptions::moveup()
{
    if (optionsSelectedrow - 1 >= -1) //check if not on the first item (play)
    {
        soundOptionsMenu[optionsSelectedrow][optionsSelectedcol].setFillColor(sf::Color::Color(253, 181, 0)); //change the pervious item's color

        optionsSelectedrow--;       //move to the upper item
        if (optionsSelectedrow == -1)
        {
            optionsSelectedrow = 1;
        }
        soundOptionsMenu[optionsSelectedrow][optionsSelectedcol].setFillColor(Color::White);  //Change the new item's color
    }
}

void soundOptions::movedown()
{
    if (optionsSelectedrow + 1 <= Max_Sound_row) //check if not on the last item (exit)
    {
        soundOptionsMenu[optionsSelectedrow][optionsSelectedcol].setFillColor(sf::Color::Color(253, 181, 0)); //change the pervious item's color

        optionsSelectedrow++;  //move to the lower item
        if (optionsSelectedrow == 2)
        {
            optionsSelectedrow = 0;
        }
        soundOptionsMenu[optionsSelectedrow][optionsSelectedcol].setFillColor(Color::White);  //change the new item's color

    }
}

void soundOptions::moveright()
{
    if (optionsSelectedcol + 1 <= Max_Sound_col) //check if not on the last item (exit)
    {
        soundOptionsMenu[optionsSelectedrow][optionsSelectedcol].setFillColor(sf::Color::Color(253, 181, 0)); //change the pervious item's color

        optionsSelectedcol++;  //move to the lower item
        if (optionsSelectedcol == 3)
        {
            optionsSelectedcol = 0;
        }
        soundOptionsMenu[optionsSelectedrow][optionsSelectedcol].setFillColor(Color::White);  //change the new item's color

    }
}

void soundOptions::moveleft()
{
    if (optionsSelectedcol - 1 >= -1) //check if not on the first item (play)
    {
        soundOptionsMenu[optionsSelectedrow][optionsSelectedcol].setFillColor(sf::Color::Color(253, 181, 0)); //change the pervious item's color

        optionsSelectedcol--;       //move to the upper item
        if (optionsSelectedcol == -1)
        {
            optionsSelectedcol = 2;
        }
        soundOptionsMenu[optionsSelectedrow][optionsSelectedcol].setFillColor(Color::White);  //Change the new item's color
    }
}

soundOptions::~soundOptions()
{
}

/*------------------------------------------------------------------------*/

Credits::Credits(float width, float height)
{
    if (!font.loadFromFile("Donald.otf"))
    {
        cout << "Error";
    }

    textCredits.setFont(font);
    textCredits.setFillColor(sf::Color::Black);
    textCredits.setString("This Game is Programmed by : ");
    textCredits.setCharacterSize(50);
    textCredits.setPosition(100, 150);

    teamName.setFont(font);
    teamName.setFillColor(sf::Color::Color(253, 181, 0));
    teamName.setOutlineColor(sf::Color::Black);
    teamName.setOutlineThickness(10);
    teamName.setString("GEN_177");
    teamName.setCharacterSize(80);
    teamName.setLetterSpacing(2);
    teamName.setPosition(225, 60);
}

void Credits::Draw(sf::RenderWindow& windowCredits)
{
    windowCredits.draw(textCredits);
    windowCredits.draw(teamName);
}

Credits::~Credits()
{
}