#ifndef MOVE_PATTERNS_HPP
#define MOVE_PATTERNS_HPP

#include "move.hpp"
#include <vector>

const static MovementPattern PAWN_MOVE_PATTERN = {
    std::vector<MoveSequence> {
        MoveSequence{{ {NORTH, 1, SLIDE} }}
    }
};

const static MovementPattern PAWN_ATTACK_PATTERN = {
    std::vector<MoveSequence> {
        MoveSequence{{ {NORTH_EAST, 1, SLIDE}}},
        MoveSequence{{ {NORTH_WEST, 1, SLIDE}}}
    }
};

#endif
