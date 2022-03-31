#pragma once

#include <vector>
#include <optional>
#include <algorithm>

#include "math/geometry.h"
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
	std::optional<Position> getMoveFromInput(const std::vector<Point>&) const;
};