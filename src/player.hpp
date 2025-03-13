#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <utility>

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
        std::pair<ChessPiece*, Position> queryPlayerMove(Board board);
};

#endif
