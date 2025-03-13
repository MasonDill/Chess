#ifndef MOVE_PATTERNS_HPP
#define MOVE_PATTERNS_HPP

#include "move.hpp"
#include <vector>

const static MovePattern PAWN_MOVE_PATTERN = {
    std::vector<Move> {
        {NORTH, 1, SLIDE},
        {NORTH, 2, SLIDE},
    }
};

const static MovePattern PAWN_ATTACK_PATTERN = {
    std::vector<Move> {
        {NORTH_EAST, 1, SLIDE},
        {NORTH_WEST, 1, SLIDE},
    }
};

#endif
