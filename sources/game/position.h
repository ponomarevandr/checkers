#pragma once

#include <array>
#include <optional>
#include <algorithm>
#include <iostream>

#include "math/geometry.h"


const size_t BOARD_SIZE = 8;

class Position {
private:
	enum class Figure {
		EMPTY,
		WHITE_SIMPLE,
		BLACK_SIMPLE,
		WHITE_QUEEN,
		BLACK_QUEEN,
	};

private:
	std::array<std::array<Figure, BOARD_SIZE>, BOARD_SIZE> board;
	int orientation = 0;

private:
	bool isWhiteCell(Point) const;
	void clear();
	static bool isValid(Point);
	Figure& field(Point);
	bool isWhite(Point);
	bool isBlack(Point);

public:
	Position();
	void initialize();
	void show() const;
	void swapSides();
	std::optional<Position> move(Point from, Point to);
};