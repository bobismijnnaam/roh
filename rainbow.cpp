// Includes I didn't make myself
#include <iostream>
#include <SFML/Graphics.hpp>

// Includes I did make myself
#include "constants.hpp"
#include "globals.hpp"
#include "rainbow.hpp"

Rainbow::Rainbow(bool fill, int x, int y) {
	int r;
	for (int i = 0; i < 7; i++) {
		r = RAIN_BASERAD + i * RAIN_DRAD;
		rainbows.push_back(sf::CircleShape(r));
		rainbows[i].setOutlineColor(colorbands[i]);
		rainbows[i].setFillColor(sf::Color::Transparent);
		rainbows[i].setOutlineThickness(RAIN_WIDTH);
		rainbows[i].setPosition(x, y);
		rainbows[i].setOrigin(r, r);
	}

	if (fill) {
		for (int i = 6; i > -1; --i) {
			stack.push_back(i);
		}
	}
}

Rainbow::~Rainbow() {

}

int Rainbow::push(int p) {
	if (stack.size() == 0) {
		stack.push_back(p);
		return PUSH_SUCCES;
	} else {
		if (stack.back() > p) {
			stack.push_back(p);
			return PUSH_SUCCES;
		} else {
			return PUSH_FAIL;
		}
	}

	return 0;
}

int Rainbow::pop() {
	int top;

	if (stack.size() > 0) {
		top = stack.back();
		stack.pop_back();
	} else {
		top = BAND_NONE;
	}

	return top;
}

int Rainbow::getSize() {
	return stack.size();
}

int Rainbow::draw(sf::RenderWindow& window) {
	for (int i = 0; i < stack.size(); ++i) {
		window.draw(rainbows[stack[i]]);
	}

	return 0;
}