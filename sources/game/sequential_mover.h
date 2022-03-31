#pragma once

#include <vector>
#include <algorithm>

#include "game/position.h"


class SequentialMover {
private:
	const Position& start;
	std::vector<Position> finishes;

private:
	static bool onlyMinFiguresNumber(std::vector<Position>&);

public:
	SequentialMover(const Position& start);
	void run();
	std::vector<Position> getMoves();
	bool isPossible(const Position& finish) const;
};