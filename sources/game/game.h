#pragma once

#include <iostream>
#include <vector>

#include "game/position.h"
#include "game/sequential_mover.h"
#include "user/interface.h"


class Game {
private:
	Position position;
	Interface interface;

public:
	Game();
	void run();
};