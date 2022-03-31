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

size_t Interface::readNumber(size_t lower_bound, size_t upper_bound) const {
	size_t result;
	while (true) {
		if (!(in >> result))
			exit(0);
		if (lower_bound <= result && result <= upper_bound)
			break;
		out << "Недопустимое значение!\n";
	}
	return result;
}

bool Interface::isValid(Point point) const {
	return 0 <= point.x && point.x < static_cast<int>(Global::BOARD_SIZE)
		&& 0 <= point.y && point.y < static_cast<int>(Global::BOARD_SIZE);
}

std::optional<std::vector<Point>> Interface::readMoveImpl() const {
	std::string input;
	if (!(in >> input))
		exit(0);
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


Interface::Interface(std::istream& in, std::ostream& out): in(in), out(out) {}

void Interface::writeGreeting() const {
	out << "=================================================================\n";
	out << "                              Шашки\n";
	out << "=================================================================\n";
	out << "Приветствуем!\n";
}

void Interface::readSettings() const {
	out << "Введите размер игровой доски (от 1 до 3):\n";
	Global::FIGURES_ROWS_NUMBER = readNumber(1, 3);
	Global::BOARD_SIZE = 2 + 2 * Global::FIGURES_ROWS_NUMBER;
	out << "Введите уровень сложности (от 1 до 5):\n";
	Global::DIFFICULTY_LEVEL = readNumber(1, 5);
}

std::vector<Point> Interface::readMove() const {
	while (true) {
		auto result = readMoveImpl();
		if (result)
			return *result;
		out << "Некорректный ввод!\n";
	}
}

void Interface::writeIllegalMove() const {
	out << "Запрещенный ход!\n";
}


void Interface::writeVictory() const {
	out << "Поздравляем, вы выиграли!\n";
}

void Interface::writeDefeat() const {
	out << "Вы проиграли\n";
}

void Interface::writeDraw() const {
	out << "Ничья повторением позиции\n";
}