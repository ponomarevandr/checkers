#include "game/position.h"


void Position::clear() {
	for (size_t i = 0; i < BOARD_SIZE; ++i) {
		board[i].fill(Figure::EMPTY);
	}
}

bool Position::isWhite(Point point) const {
	return (point.x + point.y) % 2;
}


Position::Position() {
	clear();
}

void Position::initialize() {
	clear();
	for (size_t i = 0; i < BOARD_SIZE; ++i) {
		for (size_t j = 0; j < BOARD_SIZE; ++j) {
			if (isWhite(Point(i, j)))
				continue;
			if (i <= 2)
				board[i][j] = Figure::WHITE_SIMPLE;
			if (i >= 5)
				board[i][j] = Figure::BLACK_SIMPLE;
		}
	}
}

void Position::show() {
	for (size_t i = BOARD_SIZE; i > 0; --i) {
		std::cout << i << " ";
		for (size_t j = 0; j < BOARD_SIZE; ++j) {
			if (isWhite(Point(i - 1, j))) {
				std::cout << "\033[1;47m";
			} else {
				std::cout << "\033[1;40m";
			}
			switch (board[i - 1][j]) {
			case Figure::EMPTY:
				std::cout << " ";
				break;
			case Figure::WHITE_SIMPLE:
				std::cout << "\033[1;37mo";
				break;
			case Figure::BLACK_SIMPLE:
				std::cout << "\033[1;31mo";
				break;
			case Figure::WHITE_QUEEN:
				std::cout << "\033[1;37mx";
				break;
			case Figure::BLACK_QUEEN:
				std::cout << "\033[1;31mx";
				break;
			}
		}
		std::cout << "\033[0m\n";
	}
	std::cout << "  abcdefgh\n";
}