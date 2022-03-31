#pragma once

#include <vector>
#include <string>
#include <optional>
#include <iostream>
#include <cctype>

#include "math/geometry.h"
#include "user/settings.h"


class Interface {
private:
	std::istream& in;
	std::ostream& out;

private:
	static std::vector<std::string> split(const std::string&, char);
	size_t readNumber(size_t lower_bound, size_t upper_bound) const;
	bool isValid(Point) const;
	std::optional<std::vector<Point>> readMoveImpl() const;

public:
	Interface(std::istream& in, std::ostream& out);
	void writeGreeting() const;
	void readSettings() const;
	std::vector<Point> readMove() const;
	void writeIllegalMove() const;
	void writeVictory() const;
	void writeDefeat() const;
	void writeDraw() const;
};