// Includes I didn't make myself
#include <iostream>
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "constants.hpp"
#include "gamestate.hpp"
#include "globals.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCR_W, SCR_H), "Rainbow of Hanoi");

    if (!tArrow.loadFromFile("arrow.png")) {
        std::cout << "not found!";
    }

    if (!tSplash.loadFromFile("splash.png")) {
        std::cout << "not found!";
    }

    if (!fMain.loadFromFile("Romanesque Serif.ttf")) {
        std::cout << "not found!";
    }

    gm = new cGameMan(STATE_MENU);

    while (gm->getState() != STATE_EXIT) {
        gm->currState->events(window);

        gm->currState->logic(window);

        gm->changeState();

        gm->currState->render(window);
    }

    std::cout << "Bye!";

    delete gm;

    return 0;
}