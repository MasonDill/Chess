#ifndef CHESS_HPP
#define CHESS_HPP

#include "gamestate.hpp"
#include "player.hpp"
#include "piece.hpp"

/*
    @class Chess
    @brief A class for the chess game
*/
class Chess {
    private:
        GameState* gameState;
    public:
        Chess(GameTemplate* gameTemplate) : gameState(new GameState(gameTemplate)) {};
        Chess() : Chess(new ClassicChess()) {};
        void run();
};


#endif