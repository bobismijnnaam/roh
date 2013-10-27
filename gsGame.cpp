// Includes I didn't make myself
#include <math.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "constants.hpp"
#include "globals.hpp"
#include "gsGame.hpp"

gsGame::gsGame() : ground(sf::Vector2f(SCR_W, GROUND_H)), arrow(tArrow) {
    ground.setPosition(0, SCR_H - GROUND_H);
    ground.setFillColor(clrGrass);

    int h = SCR_H - GROUND_H;
    rainbows.push_back(Rainbow(true, SCR_W * 1 / 6, h));
    rainbows.push_back(Rainbow(false, SCR_W * 3 / 6, h));
    rainbows.push_back(Rainbow(false, SCR_W * 5 / 6, h));

    arrowX = 0;
    arrow.setPosition(SCR_W * 1 / 6 + arrowX * (SCR_W * 1 / 3), 100);
    arrow.setOrigin(25, 25);
    mode = MODE_PULL;

    currBand = BAND_NONE;

    rainbowIndicator.setRadius(15);
    rainbowIndicator.setPosition(SCR_W * 1 / 6 + arrowX * (SCR_W * 1 / 3), 35);
    rainbowIndicator.setFillColor(sf::Color::Transparent);
    rainbowIndicator.setOrigin(15, 15);

    endingMsg.setFont(fMain);
    endingMsg.setString("Well done! Press [enter] to replay");
    endingMsg.setCharacterSize(32);
    endingMsg.setColor(sf::Color::Transparent);
    sf::FloatRect bounds = endingMsg.getLocalBounds();
    endingMsg.setPosition((SCR_W - bounds.width) / 2, 280);
}

gsGame::~gsGame() {

}

int gsGame::events(sf::RenderWindow& window) {
	sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            gm->setNextState(STATE_EXIT);
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Left) {
                arrowX = fmax(arrowX - 1, 0);
                arrow.setPosition(SCR_W * 1 / 6 + arrowX * (SCR_W * 1 / 3), 100);
                rainbowIndicator.setPosition(SCR_W * 1 / 6 + arrowX * (SCR_W * 1 / 3), 35);
            } else if (event.key.code == sf::Keyboard::Right) {
                arrowX = fmin(arrowX + 1, 2);
                arrow.setPosition(SCR_W * 1 / 6 + arrowX * (SCR_W * 1 / 3), 100);
                rainbowIndicator.setPosition(SCR_W * 1 / 6 + arrowX * (SCR_W * 1 / 3), 35);
            } else if (event.key.code == sf::Keyboard::Space) {
                switch (mode) {
                    case MODE_PULL:
                        currBand = rainbows[arrowX].pop();
                        if (currBand != BAND_NONE) {
                            mode = MODE_PUSH;
                            arrow.setScale(1, -1);
                            rainbowIndicator.setFillColor(colorbands[currBand]);
                        } else {
                            // Error sound?
                        }
                        break;
                    case MODE_PUSH:
                        if (rainbows[arrowX].push(currBand) == PUSH_SUCCES) {
                            mode = MODE_PULL;
                            arrow.setScale(1, 1);
                            rainbowIndicator.setFillColor(sf::Color::Transparent);

                            if (rainbows[2].getSize() == 7) {
                                mode = MODE_DONE;
                                endingMsg.setColor(sf::Color(245, 245, 220));
                                arrow.setColor(sf::Color::Transparent);
                            }
                        }
                        break;
                }
            } else if (event.key.code == sf::Keyboard::Return) {
                if (mode == MODE_DONE) {
                    gm->setNextState(STATE_GAME);
                }
            }
        }
    }

	return 0;
}

int gsGame::logic(sf::RenderWindow& window) {

	return 0;
}

int gsGame::render(sf::RenderWindow& window) {
	window.clear(clrSky);

    for (int i = 0; i < rainbows.size(); ++i) {
        rainbows[i].draw(window);
    }

    window.draw(ground);

    window.draw(arrow);

    window.draw(rainbowIndicator);

    window.draw(endingMsg);
    
    window.display();

	return 0;
}