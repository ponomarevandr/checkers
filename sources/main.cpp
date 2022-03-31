#include <iostream>
#include <optional>

#include "game/position.h"


int main() {
	Position pos;
	pos.initialize();
	while (true) {
		pos.show();
		Point from, to;
		std::cin >> from >> to;
		auto result = pos.move(from, to);
		if (!result) {
			std::cout << "Invalid move!\n";
			continue;
		}
		pos = *result;
		pos.swapSides();
	}
	return 0;
}