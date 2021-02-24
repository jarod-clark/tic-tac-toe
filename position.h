#ifndef POSITION_H
#define POSITION_H

#include <string>

class Position {
	int x;
	int y;
public:
	Position(std::string s);
	int getX();
	int getY();
};

#endif
