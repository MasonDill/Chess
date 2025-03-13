#ifndef MOVE_HPP
#define MOVE_HPP
#include <vector>

struct Position {
    int rank;
    int file;
};

enum Direction {
    NORTH,
    NORTH_EAST,
    EAST,
    SOUTH_EAST,
    SOUTH,
    SOUTH_WEST,
    WEST,
    NORTH_WEST,
    X_AXIS,
    Y_AXIS,
    DIAGONAL_NESW,
    DIAGONAL_NWSE
};

enum MoveType {
    SLIDE,
    JUMP
};

struct Move {
    static const int MAX_DISTANCE = -1;

    Direction direction;
    int distance;
    MoveType moveType;
};

struct MovePattern {
    std::vector<Move> moves;
};

std::vector<Position> getMoveDestinations(Position start, MovePattern& movePattern);

#endif
