#pragma once

#include <array>
#include <vector>
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
	static const std::array<Vector, 4> DIRECTIONS;
	static const int QUEEN_WEIGHT = 5;

	std::array<std::array<Figure, BOARD_SIZE>, BOARD_SIZE> board;
	int orientation = 0;

private:
	bool isWhiteCell(Point) const;
	void clear();
	static bool isValid(Point);
	Figure& field(Point);
	const Figure& field(Point) const;
	bool isWhite(Point) const;
	bool isBlack(Point) const;

public:
	Position();
	void initialize();
	void show() const;
	void swapSides();
	std::optional<Position> applyAtomicMove(Point from, Point to) const;
	std::vector<Position> getAtomicMoves() const;
	int mark() const;
	size_t figuresNumber() const;

	bool operator==(const Position&);
	bool operator!=(const Position&);
};