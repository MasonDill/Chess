#include "move.hpp"

std::vector<Position> getMoveDestinations(Position start, MovementPattern movePattern) {
    std::vector<Position> destinations;

    for (MoveSequence move : movePattern.moveSequences) {
        Position destination = start;

        for (MoveSequence move : movePattern.moveSequences) {
            // TODO: Implement move logic
        }
    }

    return destinations;
}