#ifndef MOVE_HPP
#define MOVE_HPP
#include <vector>

/*
    @struct Position
    @brief A struct for the position of a piece on the board
*/
struct Position {
    int rank;
    int file;
};

/*
    @enum Direction
    @brief An enum for the direction of a move
*/
enum Direction {
    NORTH,
    NORTH_EAST,
    EAST,
    SOUTH_EAST,
    SOUTH,
    SOUTH_WEST,
    WEST,
    NORTH_WEST,
    /* @brief A direction for the x-axis (WEST and EAST) */
    X_AXIS,
    /* @brief A direction for the y-axis (NORTH and SOUTH) */
    Y_AXIS,
    /* @brief A direction for the diagonal from north-east to south-west (NORTH_EAST and SOUTH_WEST) */
    DIAGONAL_NESW,
    /* @brief A direction for the diagonal from north-west to south-east (NORTH_WEST and SOUTH_EAST) */
    DIAGONAL_NWSE
};

/*
    @enum MoveType
    @brief An enum for the type of a move
*/
enum MoveType {
    /* @brief A move that cannot bypass another piece */
    SLIDE,
    /* @brief A move that permits a piece to jump (bypass) another piece */
    JUMP
};

/*
    @struct Move
    @brief A struct for a move. Represents an atomic change to piece position. May be part of a MoveSequence.
*/
struct Move {
    /* @brief A magic number to represent an infinite distance */
    static const int UNBOUNDED_DISTANCE = -1;

    /* @brief The direction of the move */
    Direction direction;
    /* @brief The distance of the move */
    int distance;
    /* @brief The type of the move */
    MoveType moveType;
};

/*
    @struct MoveSequence
    @brief A struct for a sequence of moves. Represents the movement a piece can make in a single turn.
*/
struct MoveSequence {
    std::vector<Move> moves;
};

/*
    @struct MovementPattern
    @brief A struct for the movement pattern of a piece. Represents all the possible moves a piece can make in a single turn.
*/
struct MovementPattern {
    std::vector<MoveSequence> moveSequences;
};

/*
    @brief A function to get the possible destinations of a piece from a given position
    @param start The starting position of the piece
    @param movePattern The movement pattern of the piece
    @return A vector of positions that the piece can move to
*/
std::vector<Position> getMoveDestinations(Position start, MovementPattern& movePattern);

#endif
