#pragma once

#include <vector>
#include <algorithm>

#include "game/position.h"
#include "game/sequential_mover.h"
#include "user/settings.h"


class Machine {
private:
	static const int INF = 1000;

	const Position& start;

private:
	int mark(const Position& position, size_t depth = 0) const;

public:
	Machine(const Position&);
	Position getMove() const;
};