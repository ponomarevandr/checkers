#include "user/interface.h"


std::vector<std::string> Interface::split(const std::string& text, char delimiter) {
	std::vector<std::string> result;
	result.emplace_back();
	for (char symbol : text) {
		if (symbol == delimiter) {
			result.emplace_back();
			continue;
		}
		result.back().push_back(symbol);
	}
	return result;
}

bool Interface::isValid(Point point) const {
	return 0 <= point.x && point.x < static_cast<int>(board_size)
		&& 0 <= point.y && point.y < static_cast<int>(board_size);
}

std::optional<std::vector<Point>> Interface::readMoveImpl() const {
	std::string input;
	in >> input;
	std::vector<std::string> splitted = split(input, '-');
	std::vector<Point> result;
	for (std::string& item : splitted) {
		if (item.size() != 2)
			return std::nullopt;
		Point point(std::tolower(item[0]) - 'a', item[1] - '1');
		if (!isValid(point))
			return std::nullopt;
		result.push_back(point);
	}
	return result;
}


Interface::Interface(std::istream& in, std::ostream& out, size_t board_size):
	in(in), out(out), board_size(board_size) {}

std::vector<Point> Interface::readMove() const {
	while (true) {
		auto result = readMoveImpl();
		if (result)
			return *result;
		out << "Invalid input!\n";
	}
}

void Interface::writeIllegalMove() const {
	out << "Illegal move!\n";
}


void Interface::writeVictory() const {
	out << "You winned!\n";
}

void Interface::writeDefeat() const {
	out << "You lost!\n";
}