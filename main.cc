#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "board.h"
#include "player.h"
#include "position.h"

int main() {
	std::string tmpName = "";
	char tmpSym = 0;
	std::cout << "Welcome to the wonderful world of tic tac toe. Player 1, please enter your name!" << std::endl;
	std::cin >> tmpName;
	std::cout << "Nice to meet you, " << tmpName << "! Can I get you to enter a symbol now too?" << std::endl;
	std::cin >> tmpSym;

	Player p1 = {tmpName, tmpSym};

	std::cout << "Now I would like Player 2 to enter their name please!" << std::endl;
	std::cin >> tmpName;
	std::cout << "Hello, " << tmpName << " enter your symbol!" << std::endl;
	std::cin >> tmpSym;

	Player p2 = {tmpName, tmpSym};

	std::vector<Player *> players;
	players.emplace_back(&p1);
	players.emplace_back(&p2);

	for (auto p : players) {
		std::cout << p->name << ": " << p->symbol << std::endl;
	}

	Board b;
	b.print();

	while (true) {
		for (auto p : players) {
			while (true) {
				try {
					std::cout << p->name << ", please enter a position to play in!" << std::endl;
					std::string pos;
					std::cin >> pos;
					Position n{pos};
					b.addSym(p->symbol, n);
					break;
				} catch(std::invalid_argument &e) {
					std::cerr << "ERROR: " << e.what() << std::endl;
				}
			}
			b.print();
			if (b.checkWinners()) {
				std::cout << "Congratulations, " << p->name << "! You won!" << std::endl;
				break;
			} else if (b.checkFull()) {
				std::cout << "It's a tie!" << std::endl;
				break;
			}
		}
		if (b.checkWinners() || b.checkFull()) {
			break;
		}
	}
}
