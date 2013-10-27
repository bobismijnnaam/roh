#ifndef GSMENU_HPP
#define GSMENU_HPP

// Includes I didn't make myself
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "gamestate.hpp"

class gsMenu : public cGameState {
public:
	gsMenu();
	~gsMenu();

	int events(sf::RenderWindow& window);
	int logic(sf::RenderWindow& window);
	int render(sf::RenderWindow& window);

private:
	sf::Sprite splash;
};

#endif