#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include "position.h"

class Board {
	std::vector<std::vector <char> > theBoard; 
public:
	Board();
	void addSym(char s, Position xy);
	void print();
	bool checkWinners();
	bool checkFull();
	friend std::ostream &operator<<(std::ostream &out, Board b);
};

std::ostream &operator<<(std::ostream &out, Board b);

#endif
