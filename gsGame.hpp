#ifndef GSGAME_HPP
#define GSGAME_HPP

// Includes I didn't make myself
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "gamestate.hpp"
#include "rainbow.hpp"

class gsGame : public cGameState {
public:
	int events(sf::RenderWindow& window);
	int logic(sf::RenderWindow& window);
	int render(sf::RenderWindow& window);

	gsGame();
	~gsGame();

private:
	sf::RectangleShape ground;
	std::vector<Rainbow> rainbows;
	sf::CircleShape rainbowIndicator;

	sf::Sprite arrow;
	int arrowX;
	int currBand;
	int mode;

	sf::Text endingMsg;
};

#endif