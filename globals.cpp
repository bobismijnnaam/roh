// Includes I didn't make myself
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "globals.hpp"

cGameMan* gm = NULL;

sf::Color colorbands[7] = {
	sf::Color(143, 0, 255),
	sf::Color(75, 0, 130),
	sf::Color(0, 0, 255),
	sf::Color(0, 255, 0),
	sf::Color(255, 255, 0),
	sf::Color(255, 127, 0),
	sf::Color(255, 0, 0)
};

sf::Color clrSky(135, 145, 191);
sf::Color clrGrass(107, 142, 35);

sf::Texture tArrow;
sf::Texture tSplash;
sf::Font fMain;

// // First band: red
// colorbands[0].r = 255;
// colorbands[0].g = 0;
// colorbands[0].b = 0;
// colorbands[0].a = 255;

// // Second band: orange
// colorbands[1].r = 255;
// colorbands[1].g = 127;
// colorbands[1].b = 0;

// // Band: Yellow
// colorbands[2].r = 255;
// colorbands[2].g = 255;
// colorbands[2].b = 0;

// // Band: Green
// colorbands[3].r = 0;
// colorbands[3].g = 255;
// colorbands[3].b = 0;

// // Band: Blue
// colorbands[4].r = 0;
// colorbands[4].g = 0;
// colorbands[4].b = 255;

// // Band: Indigo
// colorbands[5].r = 75;
// colorbands[5].g = 0;
// colorbands[5].b = 130;

// // Band: Violet
// colorbands[6].r = 143;
// colorbands[6].g = 0;
// colorbands[6].b = 255;