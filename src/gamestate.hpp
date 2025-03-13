#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "board.hpp"
#include "gametemplate.hpp"

/*
    @class GameState
    @brief A class for the game state of a chess game
*/
class GameState {
    private:
        Board board;
        int turn;
        bool whiteTurn;
    public:
        GameState(int ranks, int files, std::vector<ChessPiece*> pieces);
        GameState::GameState(GameTemplate* gameTemplate) : GameState(gameTemplate->ranks(), gameTemplate->files(), gameTemplate->getInitialPieces()) {};
};


#endif

