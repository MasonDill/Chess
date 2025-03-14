#include <vector>

#include "move.hpp"

/*** Helper functions ***/

/*
    Translates a position by a move.

    Returns a vector because directions can be ambiguous (Y_AXIS, , DIAGONAL)
*/
static std::vector<Position> translatePosition(Position start, Move move) {
    std::vector<Position> destinations;

    if (move.direction == Direction::NORTH || move.direction == Direction::Y_AXIS){
        Position destination = start;
        destination.rank += move.distance;
        destinations.push_back(destination);
    }

    if (move.direction == Direction::SOUTH || move.direction == Direction::Y_AXIS){
        Position destination = start;
        destination.rank -= move.distance;
        destinations.push_back(destination);
    }

    if (move.direction == Direction::EAST || move.direction == Direction::X_AXIS){
        Position destination = start;
        destination.file += move.distance;
        destinations.push_back(destination);
    }

    if (move.direction == Direction::WEST || move.direction == Direction::X_AXIS){
        Position destination = start;
        destination.file -= move.distance;
        destinations.push_back(destination);
    }

    if (move.direction == Direction::NORTH_EAST || move.direction == Direction::DIAGONAL_NESW){
        Position destination = start;
        destination.rank += move.distance;
        destination.file += move.distance;
        destinations.push_back(destination);
    }

    if (move.direction == Direction::NORTH_WEST || move.direction == Direction::DIAGONAL_NWSE){
        Position destination = start;
        destination.rank += move.distance;
        destination.file -= move.distance;
        destinations.push_back(destination);
    }

    if (move.direction == Direction::SOUTH_EAST || move.direction == Direction::DIAGONAL_NWSE){
        Position destination = start;
        destination.rank -= move.distance;
        destination.file += move.distance;
        destinations.push_back(destination);
    }

    if (move.direction == Direction::SOUTH_WEST || move.direction == Direction::DIAGONAL_NESW){
        Position destination = start;
        destination.rank -= move.distance;
        destination.file -= move.distance;
        destinations.push_back(destination);
    }

    return destinations;
}

/*
    Calculates all the destinations of a move sequence.
*/
static std::vector<Position> calculateDestinations(Position start, const MoveSequence& moves) {
    std::vector<Position> destinations;
    for (const Move& move : moves.moves) {
        destinations.insert(destinations.end(), translatePosition(start, move).begin(), translatePosition(start, move).end());
    }
    return destinations;
}

/*** Public functions ***/

std::vector<Position> getMoveDestinations(Position start, MovementPattern movePattern) {
    std::vector<Position> destinations;

    for (const MoveSequence& moves : movePattern.moveSequences) {
        std::vector<Position> moveDestinations = calculateDestinations(start, moves);
        destinations.insert(destinations.end(), moveDestinations.begin(), moveDestinations.end());
    }

    return destinations;
}

bool canReachDestination(Position start, Position end, MovementPattern movePattern) {
    for (const MoveSequence& moves : movePattern.moveSequences) {
        std::vector<Position> moveDestinations = calculateDestinations(start, moves);

        // Check if the end position is in the list of destinations, if so, the move is legal - return immediately
        for (const Position& destination : moveDestinations) {
            if (destination == end) {
                return true;
            }
        }
    }

    return false;
}
