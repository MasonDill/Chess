#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <utility>
#include <exception>

#include "move.hpp"
#include "gamestate.hpp"
#include "piece.hpp"

/*
    @class Player
    @brief A class for a player
*/
class Player {
    private:
        Color color;
    public:
        Player(Color color) : color(color) {};
        std::pair<ChessPiece*, Position> queryPlayerMove(Board& board);
};

class InvalidInputException : public std::exception {
    public:
        InvalidInputException(const std::string& message) : message(message) {}
        const char* what() const noexcept override {
            return message.c_str();
        }
    private:
        std::string message;
};

class ExitGameException : public std::exception {
    public:
        ExitGameException(const std::string& message) : message(message) {}
        const char* what() const noexcept override {
            return message.c_str();
        }
    private:
        std::string message;
};

#endif
