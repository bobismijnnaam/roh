#ifndef RAINBOW_HPP
#define RAINBOW_HPP

// Includes I didn't make myself
#include <SFML/Graphics.hpp>
#include <vector>

class Rainbow {
public:
	Rainbow(bool fill, int x, int y);
	~Rainbow();

	int push(int p);
	int pop();

	int getSize();

	int draw(sf::RenderWindow& window);

private:
	// sf::CircleShape rainbows[7];
	std::vector<sf::CircleShape> rainbows;
	std::vector<int> stack;

	sf::CircleShape circle;
} ;

#endif
