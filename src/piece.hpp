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

class Knight : public ChessPiece {
    public:
        Knight(Color color, Position position) : ChessPiece(color,
                                            position,
                                            KNIGHT,
                                            KNIGHT_MOVE_PATTERN,
                                            KNIGHT_ATTACK_PATTERN) {}

        virtual std::string toString() const override {
            return "N";
        }

        ~Knight() override = default;
};

class Bishop : public ChessPiece {
    public:
        Bishop(Color color, Position position) : ChessPiece(color,
                                            position,
                                            BISHOP,
                                            BISHOP_MOVE_PATTERN,
                                            BISHOP_ATTACK_PATTERN) {}

        virtual std::string toString() const override {
            return "B";
        }

        ~Bishop() override = default;
};

class Queen : public ChessPiece {
    public:
        Queen(Color color, Position position) : ChessPiece(color,
                                            position,
                                            QUEEN,
                                            QUEEN_MOVE_PATTERN,
                                            QUEEN_ATTACK_PATTERN) {}

        virtual std::string toString() const override {
            return "Q";
        }

        ~Queen() override = default;
};

class King : public ChessPiece {
    public:
        King(Color color, Position position) : ChessPiece(color,
                                            position,
                                            KING,
                                            KING_MOVE_PATTERN,
                                            KING_ATTACK_PATTERN) {}

        virtual std::string toString() const override {
            return "K";
        }

        ~King() override = default;
};

#endif
