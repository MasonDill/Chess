#ifndef CHESS_HPP
#define CHESS_HPP

#include "gamestate.hpp"

/*
    @class Chess
    @brief A class for the chess game
*/
class Chess {
    private:
        GameState gameState;
    public:
        Chess() : gameState(new ClassicChess()) {};
        Chess(GameTemplate* gameTemplate) : gameState(gameTemplate) {};
        void run();
};

#endif