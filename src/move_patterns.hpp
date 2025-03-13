#ifndef MOVE_PATTERNS_HPP
#define MOVE_PATTERNS_HPP

#include "move.hpp"
#include <vector>

/*
    @file move_patterns.hpp
    @brief A file for the move patterns of the pieces
*/

const static MovementPattern PAWN_MOVE_PATTERN = {
    std::vector<MoveSequence> {
        MoveSequence{{ {NORTH, 1, SLIDE} }},
        MoveSequence{{ {NORTH, 2, SLIDE} }}
    }
};
const static MovementPattern PAWN_ATTACK_PATTERN = {
    std::vector<MoveSequence> {
        MoveSequence{{ {NORTH_EAST, 1, SLIDE}}},
        MoveSequence{{ {NORTH_WEST, 1, SLIDE}}}
    }
};

const static MovementPattern ROOK_MOVE_PATTERN = {
    std::vector<MoveSequence> {
        MoveSequence{{ {NORTH, Move::UNBOUNDED_DISTANCE, SLIDE} }},
        MoveSequence{{ {EAST, Move::UNBOUNDED_DISTANCE, SLIDE} }},
        MoveSequence{{ {SOUTH, Move::UNBOUNDED_DISTANCE, SLIDE} }},
        MoveSequence{{ {WEST, Move::UNBOUNDED_DISTANCE, SLIDE} }},
    }
};
const static MovementPattern ROOK_ATTACK_PATTERN = ROOK_MOVE_PATTERN;

const static MovementPattern KNIGHT_MOVE_PATTERN = {
    std::vector<MoveSequence> {
        MoveSequence{{ {Y_AXIS, 2, JUMP}, {X_AXIS, 1, JUMP} }},
        MoveSequence{{ {X_AXIS, 2, JUMP}, {Y_AXIS, 1, JUMP} }},
    }
};
const static MovementPattern KNIGHT_ATTACK_PATTERN = KNIGHT_MOVE_PATTERN;

const static MovementPattern BISHOP_MOVE_PATTERN = {
    std::vector<MoveSequence> {
        MoveSequence{{ {DIAGONAL_NESW, Move::UNBOUNDED_DISTANCE, SLIDE} }},
        MoveSequence{{ {DIAGONAL_NWSE, Move::UNBOUNDED_DISTANCE, SLIDE} }}
    }
};
const static MovementPattern BISHOP_ATTACK_PATTERN = BISHOP_MOVE_PATTERN;

const static MovementPattern QUEEN_MOVE_PATTERN = {
    std::vector<MoveSequence> {
        MoveSequence{{ {NORTH, Move::UNBOUNDED_DISTANCE, SLIDE} }},
        MoveSequence{{ {EAST, Move::UNBOUNDED_DISTANCE, SLIDE} }},
        MoveSequence{{ {SOUTH, Move::UNBOUNDED_DISTANCE, SLIDE} }},
        MoveSequence{{ {WEST, Move::UNBOUNDED_DISTANCE, SLIDE} }},
        MoveSequence{{ {DIAGONAL_NESW, Move::UNBOUNDED_DISTANCE, SLIDE} }},
        MoveSequence{{ {DIAGONAL_NWSE, Move::UNBOUNDED_DISTANCE, SLIDE} }}
    }
};
const static MovementPattern QUEEN_ATTACK_PATTERN = QUEEN_MOVE_PATTERN;

const static MovementPattern KING_MOVE_PATTERN = {
    std::vector<MoveSequence> {
        MoveSequence{{ {NORTH, 1, SLIDE} }},
        MoveSequence{{ {EAST, 1, SLIDE} }},
        MoveSequence{{ {SOUTH, 1, SLIDE} }},
        MoveSequence{{ {WEST, 1, SLIDE} }},
        MoveSequence{{ {NORTH_EAST, 1, SLIDE} }},
        MoveSequence{{ {NORTH_WEST, 1, SLIDE} }},
        MoveSequence{{ {SOUTH_EAST, 1, SLIDE} }},
        MoveSequence{{ {SOUTH_WEST, 1, SLIDE} }}
    }
};
const static MovementPattern KING_ATTACK_PATTERN = KING_MOVE_PATTERN;

#endif  
