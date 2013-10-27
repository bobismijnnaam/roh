// Includes I didn't make myself
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "globals.hpp"
#include "gsMenu.hpp"

gsMenu::gsMenu() : splash(tSplash) {
	
}

gsMenu::~gsMenu() {

}

int gsMenu::events(sf::RenderWindow& window) {
	sf::Event event;

    while (window.pollEvent(event)) {
    	if (event.type == sf::Event::Closed) {
    		gm->setNextState(STATE_EXIT);
    	} else if (event.type == sf::Event::KeyReleased) {
    		if (event.key.code == sf::Keyboard::Space) {
    			gm->setNextState(STATE_GAME);
    		}
    	}
    }

	return 0;
}

int gsMenu::logic(sf::RenderWindow& window) {

	return 0;
}

int gsMenu::render(sf::RenderWindow& window) {
	window.clear();

	window.draw(splash);

	window.display();

	return 0;
}
