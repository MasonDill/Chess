#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>
#include <vector>

#include "move.hpp"
#include "move_patterns.hpp"

enum Color {
    WHITE,
    BLACK
};

enum PieceType {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

// Abstract base class for all chess pieces
class ChessPiece {
    private:
        Color color;
        Position position;
        PieceType type;
        MovementPattern movePattern;
        MovementPattern attackPattern;
    public:
        ChessPiece(Color color, Position position, PieceType type, MovementPattern movePattern, MovementPattern attackPattern) : color(color), position(position), type(type), movePattern(movePattern), attackPattern(attackPattern) {}
        virtual ~ChessPiece() = default;
        
        virtual std::string toString() const = 0;
        
        Color getColor() const { return color; }
        Position getPosition() const { return position; }
        PieceType getType() const { return type; }
};

class Pawn : public ChessPiece {
    private:
        bool isFirstMove;
    public:
        Pawn(Color color, Position position) : ChessPiece(color,
                                            position,
                                            PAWN,
                                            PAWN_MOVE_PATTERN,
                                            PAWN_ATTACK_PATTERN),
                                            isFirstMove(true) {}

        virtual std::string toString() const override {
            return "P";
        }

        ~Pawn() override = default;
};

class Rook : public ChessPiece {
    public:
        Rook(Color color, Position position) : ChessPiece(color,
                                            position,
                                            ROOK,
                                            ROOK_MOVE_PATTERN,
                                            ROOK_ATTACK_PATTERN) {}

        virtual std::string toString() const override {
            return "R";
        }

        ~Rook() override = default;
};
#endif
