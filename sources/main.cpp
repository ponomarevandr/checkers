#include <iostream>
#include <vector>

#include "game/position.h"
#include "game/sequential_mover.h"


int main() {
	Position pos;
	pos.board[4][4] = Position::Figure::BLACK_SIMPLE;
	pos.board[3][1] = Position::Figure::BLACK_SIMPLE;
	pos.board[1][3] = Position::Figure::BLACK_SIMPLE;
	pos.board[0][4] = Position::Figure::WHITE_QUEEN;
	pos.show();
	SequentialMover mover(pos);
	mover.run();
	auto result = mover.getMoves();
	for (const Position& p : result) {
		p.show();
	}
	return 0;
}