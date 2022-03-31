#include <iostream>
#include <vector>

#include "game/game.h"


int main() {
	Game game(std::cin, std::cout);
	game.run();
	return 0;
}