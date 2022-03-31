#include "game/game.h"


Game::Game(): interface(std::cin, std::cout, BOARD_SIZE) {
	position.initialize();
}

void Game::run() {
	while (true) {
		position.show();
		while (true) {
			std::vector<Point> user_move = interface.readMove();
			SequentialMover mover(position);
			mover.run();
			auto next = mover.getMoveFromInput(user_move);
			if (!next) {
				interface.writeIllegalMove();
				continue;
			}
			position = std::move(*next);
			break;
		}
		position.swapSides();
	}
}