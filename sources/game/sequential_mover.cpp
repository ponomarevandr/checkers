#include "game/sequential_mover.h"


bool SequentialMover::onlyMinFiguresNumber(std::vector<Position>& positions) {
	if (positions.empty())
		return true;
	size_t size_before = positions.size();
	size_t min_figures = positions[0].figuresNumber();
	for (const Position& position : positions) {
		min_figures = std::min(min_figures, position.figuresNumber());
	}
	std::vector<Position> tmp = std::move(positions);
	positions.clear();
	for (const Position& position : tmp) {
		if (position.figuresNumber() == min_figures)
			positions.push_back(std::move(position));
	}
	return positions.size() == size_before;
}


SequentialMover::SequentialMover(const Position& start): start(start) {}

void SequentialMover::run() {
	finishes = start.getAtomicMoves();
	if (onlyMinFiguresNumber(finishes))
		return;
	std::vector<Position> intermediate = std::move(finishes);
	finishes.clear();
	while (!intermediate.empty()) {
		Position position = std::move(intermediate.back());
		intermediate.pop_back();
		std::vector<Position> next = position.getAtomicMoves();
		if (onlyMinFiguresNumber(next)) {
			finishes.push_back(std::move(position));
			continue;
		}
		for (Position& position : next) {
			intermediate.push_back(std::move(position));
		}
	}
}

std::vector<Position> SequentialMover::getMoves() {
	return std::move(finishes);
}

std::optional<Position> SequentialMover::getMoveFromInput(const std::vector<Point>& input) const {
	Position current = start;
	for (size_t i = 0; i + 1 < input.size(); ++i) {
		auto result = current.applyAtomicMove(input[i], input[i + 1]);
		if (!result)
			return std::nullopt;
		current = std::move(*result);
	}
	for (const Position& candidate : finishes) {
		if (current == candidate)
			return current;
	}
	return std::nullopt;
}