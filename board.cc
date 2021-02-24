#include <vector>
#include <iostream>
#include "board.h"
#include "position.h"

Board::Board() {
	for (size_t r = 0; r < 3; ++r) {
		std::vector<char> tmp;
		for (size_t c = 0; c < 3; ++c) {
			tmp.emplace_back(' ');
		}
		theBoard.emplace_back(tmp);
	}
}

void Board::addSym(char s, Position xy) {
	if (theBoard[xy.getY()][xy.getX()] != ' ') {
		throw std::invalid_argument("That square is already occupied!");
	}
	theBoard[xy.getY()][xy.getX()] = s;
}

void Board::print() {
	std::cout << *this;
}

bool Board::checkWinners() {
	for (size_t r = 0; r < 3; ++r) {
		if (theBoard[r][0] == theBoard[r][1] && theBoard[r][1] == theBoard[r][2] && theBoard[r][2] != ' ') {
			return true;
		}
	}

	for (size_t c = 0; c < 3; ++c) {
		if (theBoard[0][c] == theBoard[1][c] && theBoard[1][c] == theBoard[2][c] && theBoard[2][c] != ' ') {
			return true;
		}
	}

	if (theBoard[0][0] == theBoard[1][1] && theBoard[1][1] == theBoard[2][2] && theBoard[2][2] != ' ') {
		return true;
	}

	if (theBoard[0][2] == theBoard[1][1] && theBoard[1][1] == theBoard[2][0] && theBoard[2][0] != ' ') {
		return true;
	}
	return false;
}

bool Board::checkFull() {
	for (size_t r = 0; r < 3; ++r) {
		for (size_t c = 0; c < 3; ++c) {
			if (theBoard[r][c] == ' ') {
				return false;
			}
		}
	}
	return true;
}

std::ostream &operator<<(std::ostream &out, Board b) {
	out << "   1   2   3 " << std::endl;
	out << "A  " << b.theBoard[0][0] << " ┃ " << b.theBoard[0][1] << " ┃ " << b.theBoard[0][2] << " " << std::endl;
	out << "  ━━━╋━━━╋━━━" << std::endl;
	out << "B  " << b.theBoard[1][0] << " ┃ " << b.theBoard[1][1] << " ┃ " << b.theBoard[1][2] << " " << std::endl;
	out << "  ━━━╋━━━╋━━━" << std::endl;
	out << "C  " << b.theBoard[2][0] << " ┃ " << b.theBoard[2][1] << " ┃ " << b.theBoard[2][2] << " " << std::endl;
	return out;
}
