#include "game/game.h"


void Game::userIteration() {
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
}

void Game::machineIteration() {
	Machine machine(position);
	position = machine.getMove();
}

bool Game::isGameContinuing() const {
	SequentialMover mover(position);
	mover.run();
	std::vector<Position> next = mover.getMoves();
	return !next.empty();
}


Game::Game(std::istream& in, std::ostream& out): interface(in, out) {}

void Game::run() {
	interface.writeGreeting();
	interface.readSettings();
	position.initialize();
	position.show();
	while (isGameContinuing()) {
		if (is_user_turn) {
			userIteration();
		} else {
			machineIteration();
		}
		if (!is_user_turn) {
			position.swapSides();
		}
		position.show();
		if (!is_user_turn) {
			position.swapSides();
		}
		position.swapSides();
		is_user_turn = !is_user_turn;
	}
	if (is_user_turn) {
		interface.writeDefeat();
	} else {
		interface.writeVictory();
	}
}