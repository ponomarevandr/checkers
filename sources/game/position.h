#pragma once

#include <vector>
#include <optional>
#include <algorithm>
#include <iostream>

#include "math/geometry.h"
#include "user/settings.h"


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

	std::vector<std::vector<Figure>> board;
	int orientation = 0;
	Point latest_moved;

private:
	bool isWhiteCell(Point) const;
	void clear();
	static bool isValid(Point);
	Figure& field(Point);
	const Figure& field(Point) const;
	bool isWhite(Point) const;
	bool isBlack(Point) const;
	void getAtomicMovesImpl(Point, std::vector<Position>&) const;

public:
	Position();
	void initialize();
	void show() const;
	void swapSides();
	std::optional<Position> applyAtomicMove(Point from, Point to) const;
	std::vector<Position> getAtomicMoves(bool of_latest = false) const;
	int mark() const;
	size_t figuresNumber() const;

	bool operator==(const Position&) const;
	bool operator!=(const Position&) const;
};