#pragma once

#include <vector>
#include <iostream>

#include "game/position.h"
#include "game/sequential_mover.h"
#include "game/machine.h"
#include "user/interface.h"


class Game {
private:
	Position position;
	Interface interface;
	bool is_user_turn = true;
	std::vector<Position> history;

private:
	void userIteration();
	void machineIteration();
	bool isGameContinuing() const;
	size_t getTimesInHistory(const Position&) const;

public:
	Game(std::istream&, std::ostream&);
	void run();
};