#include "game/machine.h"


int Machine::mark(const Position& position, size_t depth) const {
	if (depth == MAX_DEPTH)
		return position.mark();
	SequentialMover mover(position);
	mover.run();
	std::vector<Position> next = mover.getMoves();
	if (next.empty())
		return -INF;
	int result = -INF;
	for (Position& position : next) {
		position.swapSides();
		int current = -mark(position, depth + 1);
		result = std::max(result, current);
	}
	return result;
}


Machine::Machine(const Position& start): start(start) {}

Position Machine::getMove() const {
	SequentialMover mover(start);
	mover.run();
	std::vector<Position> next = mover.getMoves();
	size_t index_best = 0;
	int mark_best = -INF;
	for (size_t i = 0; i < next.size(); ++i) {
		next[i].swapSides();
		int mark_current = -mark(next[i]);
		if (mark_current > mark_best) {
			mark_best = mark_current;
			index_best = i;
		}
		next[i].swapSides();
	}
	return next[index_best];
}