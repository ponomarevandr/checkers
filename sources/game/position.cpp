#include "game/position.h"


bool Position::isWhiteCell(Point point) const {
	return (point.x + point.y + orientation) % 2;
}

void Position::clear() {
	for (size_t i = 0; i < BOARD_SIZE; ++i) {
		board[i].fill(Figure::EMPTY);
	}
}

bool Position::isValid(Point point) {
	return point.x >= 0 && point.x < static_cast<int>(BOARD_SIZE)
		&& point.y >= 0 && point.y < static_cast<int>(BOARD_SIZE);
}

Position::Figure& Position::field(Point point) {
	return board[point.x][point.y];
}

bool Position::isWhite(Point point) {
	return field(point) == Figure::WHITE_SIMPLE || field(point) == Figure::WHITE_QUEEN;
}

bool Position::isBlack(Point point) {
	return field(point) == Figure::BLACK_SIMPLE || field(point) == Figure::BLACK_QUEEN;
}


Position::Position() {
	clear();
}

void Position::initialize() {
	clear();
	for (size_t i = 0; i < BOARD_SIZE; ++i) {
		for (size_t j = 0; j < BOARD_SIZE; ++j) {
			if (isWhiteCell(Point(i, j)))
				continue;
			if (i <= 2)
				board[i][j] = Figure::WHITE_SIMPLE;
			if (BOARD_SIZE - i - 1 <= 2)
				board[i][j] = Figure::BLACK_SIMPLE;
		}
	}
}

void Position::show() const {
	for (size_t i = BOARD_SIZE; i > 0; --i) {
		std::cout << i << " ";
		for (size_t j = 0; j < BOARD_SIZE; ++j) {
			if (isWhiteCell(Point(i - 1, j))) {
				std::cout << "\033[1;47m";
			} else {
				std::cout << "\033[1;40m";
			}
			switch (board[i - 1][j]) {
			case Figure::EMPTY:
				std::cout << " ";
				break;
			case Figure::WHITE_SIMPLE:
				std::cout << "\033[1;37mO";
				break;
			case Figure::BLACK_SIMPLE:
				std::cout << "\033[1;31mO";
				break;
			case Figure::WHITE_QUEEN:
				std::cout << "\033[1;37mX";
				break;
			case Figure::BLACK_QUEEN:
				std::cout << "\033[1;31mX";
				break;
			}
		}
		std::cout << "\033[0m\n";
	}
	std::cout << "  ";
	for (size_t i = 0; i < BOARD_SIZE; ++i) {
		std::cout << static_cast<char>('a' + i);
	}
	std::cout << "\n";
}

void Position::swapSides() {
	for (size_t i = 0; i < BOARD_SIZE; ++i) {
		for (size_t j = 0; j < BOARD_SIZE; ++j) {
			switch (board[i][j]) {
			case Figure::WHITE_SIMPLE:
				board[i][j] = Figure::BLACK_SIMPLE;
				break;
			case Figure::BLACK_SIMPLE:
				board[i][j] = Figure::WHITE_SIMPLE;
				break;
			case Figure::WHITE_QUEEN:
				board[i][j] = Figure::BLACK_QUEEN;
				break;
			case Figure::BLACK_QUEEN:
				board[i][j] = Figure::WHITE_QUEEN;
				break;
			default:
				break;
			}
		}
	}
	for (size_t i = 0; 2 * i < BOARD_SIZE; ++i) {
		std::swap(board[i], board[BOARD_SIZE - 1 - i]);
	}
	orientation = 1 - orientation;
}

std::optional<Position> Position::move(Point from, Point to) {
	if (!isWhite(from))
		return std::nullopt;
	if (field(to) != Figure::EMPTY)
		return std::nullopt;
	Vector movement = to - from;
	Vector direction = movement.simplified();
	if (direction.lengthSquared() != 2)
		return std::nullopt;
	if (field(from) == Figure::WHITE_SIMPLE && movement.y != 1) {
		if (movement.lengthSquared() != 8)
			return std::nullopt;
		if (!isBlack(from + direction))
			return std::nullopt;
	}
	if (field(from) == Figure::WHITE_QUEEN) {
		size_t counter = 0;
		for (Point current = from + direction; current != to; current += direction) {
			if (isWhite(current))
				return std::nullopt;
			if (isBlack(current))
				++counter;
		}
		if (counter > 1)
			return std::nullopt;
	}
	Position result = *this;
	for (Point current = from + direction; current != to; current += direction) {
		result.field(current) = Figure::EMPTY;
	}
	result.field(to) = result.field(from);
	result.field(from) = Figure::EMPTY;
	return result;
}