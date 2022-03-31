#include <iostream>
#include <vector>

#include "game/position.h"


int main() {
	Position pos;
	pos.initialize();
	for (size_t i = 0; i < 20; ++i) {
		pos.show();
		auto ways = pos.getAtomicMoves();
		if (ways.size() == 0)
			break;
		pos = ways[0];
		pos.swapSides();
		ways = pos.getAtomicMoves();
		if (ways.size() == 0)
			break;
		pos = ways[0];
		pos.swapSides();
		std::cout << pos.figuresNumber() << " " << pos.mark() << "\n";
	}
	return 0;
}