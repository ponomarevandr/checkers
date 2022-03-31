#pragma once

#include <vector>
#include <algorithm>

#include "game/position.h"
#include "game/sequential_mover.h"


class Machine {
private:
	static const size_t MAX_DEPTH = 3;
	static const int INF = 1000;

	const Position& start;

private:
	int mark(const Position& position, size_t depth = 0) const;

public:
	Machine(const Position&);
	Position getMove() const;
};