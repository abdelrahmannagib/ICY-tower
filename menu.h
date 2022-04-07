#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define Max_main_menu 5
#define Max_HowtoPlay_menu 3
#define Max_Sound_col 3
#define Max_Sound_row 2



using namespace std;


class Menu
{
public:
    Menu(float width, float height);



    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();

    int mainMenuPressed()
    {
        return mainMenuSelected;
    }



    ~Menu();
private:
    int mainMenuSelected;
    sf::Font font;
    sf::Text mainMenu[Max_main_menu];
    sf::Text teamName;

};


class HowtoPlay
{
public:
    HowtoPlay(float width, float height);


    void DRAW(sf::RenderWindow& windowHowToPlay);


    int howtoplayPressed()
    {
        return HowtoPlaySelected;
    }


    ~HowtoPlay();
private:

    sf::Font font;
    int HowtoPlaySelected;
    sf::Text HowtoPlayMenu[Max_HowtoPlay_menu];

};

class soundOptions
{
public:
    soundOptions(float width, float height);
    void draw(sf::RenderWindow& windowSound);
    void moveup();
    void movedown();
    void moveright();
    void moveleft();

    int soundOptionsIsPressedrow()
    {
        return optionsSelectedrow;
    }
    int soundOptionsIsPressedcol()
    {
        return optionsSelectedcol;
    }

    ~soundOptions();

private:
    int optionsSelectedrow, optionsSelectedcol;
    sf::Font font;
    sf::Text soundOptionsMenu[Max_Sound_row][Max_Sound_col];
    
};

class Credits
{
public:
    Credits(float width, float height);
    void Draw(sf::RenderWindow& windowCredits);
    ~Credits();

private:
    sf::Font font;
    sf::Text textCredits;
    sf::Text teamName;
};

