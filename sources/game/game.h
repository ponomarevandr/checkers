#pragma once

#include <iostream>
#include <vector>

#include "game/position.h"
#include "game/sequential_mover.h"
#include "game/machine.h"
#include "user/interface.h"


class Game {
private:
	Position position;
	Interface interface;
	bool is_user_turn = true;

private:
	void userIteration();
	void machineIteration();
	bool isGameContinuing() const;

public:
	Game();
	void run();
};