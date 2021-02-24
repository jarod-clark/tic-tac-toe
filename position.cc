#include <string>
#include <stdexcept>
#include "position.h"

Position::Position(std::string s) {
	if (s[0] == 'A' || s[0] == 'a') {
		y = 0;
	} else if (s[0] == 'B' || s[0] == 'b') {
		y = 1;
	} else if (s[0] == 'C' || s[0] == 'c') {
		y = 2;
	} else {
		throw std::invalid_argument("Position " + s + " does not exist!");
	}

	if (s[1] == '1') {
		x = 0;
	} else if (s[1] == '2') {
		x = 1;
	} else if (s[1] == '3') {
		x = 2;
	} else {
		throw std::invalid_argument("Position " + s + " does not exist!");
	}
}

int Position::getX () {
	return x;
}

int Position::getY() {
	return y;
}
