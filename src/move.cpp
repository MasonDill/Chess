#include "move.hpp"

std::vector<Position> getMoveDestinations(Position start, MovementPattern& movePattern) {
    std::vector<Position> destinations;

    for (MoveSequence move : movePattern.moves) {
        Position destination = start;

        for (MoveSequence move : movePattern.moves) {
            // TODO: Implement move logic
        }
    }

    return destinations;
}