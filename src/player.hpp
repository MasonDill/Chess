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
        bool isWhite;
    public:
        Player(bool isWhite) : isWhite(isWhite) {};
        std::pair<ChessPiece*, MoveSequence> queryPlayerMove(GameState& gameState);
};

#endif
