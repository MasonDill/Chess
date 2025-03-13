#include "move.hpp"

std::vector<Position> getMoveDestinations(Position start, MovePattern& movePattern) {
    std::vector<Position> destinations;

    for (Move move : movePattern.moves) {
        Position destination = start;

        for (Move move : movePattern.moves) {
            // TODO: Implement move logic
        }
    }

    return destinations;
}