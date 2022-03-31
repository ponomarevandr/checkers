#pragma once

#include <array>
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

private:
	void clear();
	bool isWhite(Point point) const;

public:
	Position();
	void initialize();
	void show();
};