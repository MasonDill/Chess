#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>
#include <vector>

#include "move.hpp"
#include "move_patterns.hpp"

/*
    @enum Color
    @brief Enum for the color of a piece
*/
enum Color {
    WHITE = 0b01,
    BLACK = 0b10,
    GRAY = 0b11 // (WHITE | BLACK) -> (WHITE & GRAY) == 1, (BLACK & GRAY) == 2
};

/*
    @enum PieceType
    @brief Enum for the type of a piece
*/
enum PieceType {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

/*
    @class ChessPiece
    @brief Abstract base class for all chess pieces
*/
class ChessPiece {
    private:
        /* @brief The color of the piece */
        Color color;
        
        /* @brief The type of the piece */
        PieceType type;

        /* @brief The movement pattern of the piece */
        MovementPattern movePattern;

        /* @brief The attack pattern of the piece */
        MovementPattern attackPattern;

    public:
        /* @brief The position of the piece */
        Position position;

        /*
            @brief Constructor for the ChessPiece class
            @param color The color of the piece
            @param position The position of the piece
            @param type The type of the piece
            @param movePattern The movement pattern of the piece
            @param attackPattern The attack pattern of the piece

        */
        ChessPiece(Color color, Position position, PieceType type, MovementPattern movePattern, MovementPattern attackPattern) : color(color), position(position), type(type), movePattern(movePattern), attackPattern(attackPattern) {}

        /* @brief Destructor for the ChessPiece class */
        virtual ~ChessPiece() = default;

        /* @brief Returns a string representation of the piece */
        virtual std::string toString() const = 0;
        
        /* @brief Returns the color of the piece */
        Color getColor() const { return color; }

        /* @brief Returns the type of the piece */
        PieceType getType() const { return type; }

        /* @brief Returns the movement pattern of the piece */
        MovementPattern getMovePattern() const { return movePattern; }

        /* @brief Returns the attack pattern of the piece */
        MovementPattern getAttackPattern() const { return attackPattern; }
};

/*
    @class Pawn
    @brief A class for the pawn piece
*/
class Pawn : public ChessPiece {
    private:
        /* @brief Whether the pawn has made its first move */
        bool isFirstMove;
    public:
        Pawn(Color color, Position position) : ChessPiece(color,
                                            position,
                                            PAWN,
                                            PAWN_MOVE_PATTERN,
                                            PAWN_ATTACK_PATTERN),
                                            isFirstMove(true) {}

        std::string toString() const override {
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

        std::string toString() const override {
            return "R";
        }

        ~Rook() override = default;
};

/*
    @class Knight
    @brief A class for the knight piece
*/
class Knight : public ChessPiece {
    public:
        Knight(Color color, Position position) : ChessPiece(color,
                                            position,
                                            KNIGHT,
                                            KNIGHT_MOVE_PATTERN,
                                            KNIGHT_ATTACK_PATTERN) {}

        std::string toString() const override {
            return "N";
        }

        ~Knight() override = default;
};

/*
    @class Bishop
    @brief A class for the bishop piece
*/
class Bishop : public ChessPiece {
    public:
        Bishop(Color color, Position position) : ChessPiece(color,
                                            position,
                                            BISHOP,
                                            BISHOP_MOVE_PATTERN,
                                            BISHOP_ATTACK_PATTERN) {}

        std::string toString() const override {
            return "B";
        }

        ~Bishop() override = default;
};

/*
    @class Queen
    @brief A class for the queen piece
*/
class Queen : public ChessPiece {
    public:
        Queen(Color color, Position position) : ChessPiece(color,
                                            position,
                                            QUEEN,
                                            QUEEN_MOVE_PATTERN,
                                            QUEEN_ATTACK_PATTERN) {}

        std::string toString() const override {
            return "Q";
        }

        ~Queen() override = default;
};

/*
    @class King
    @brief A class for the king piece
*/
class King : public ChessPiece {
    public:
        King(Color color, Position position) : ChessPiece(color,
                                            position,
                                            KING,
                                            KING_MOVE_PATTERN,
                                            KING_ATTACK_PATTERN) {}

        std::string toString() const override {
            return "K";
        }

        ~King() override = default;
};

#endif
