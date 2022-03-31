#pragma once

#include <vector>
#include <string>
#include <optional>
#include <iostream>
#include <cctype>

#include "math/geometry.h"


class Interface {
private:
	std::istream& in;
	std::ostream& out;
	size_t board_size;

private:
	static std::vector<std::string> split(const std::string&, char);
	bool isValid(Point) const;
	std::optional<std::vector<Point>> readMoveImpl();

public:
	Interface(std::istream& in, std::ostream& out, size_t board_size);
	std::vector<Point> readMove();
	void writeIllegalMove();
};