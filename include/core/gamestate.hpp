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
        GameState(GameTemplate* gameTemplate);

        /*
            @enum GameOutcome
            @brief An enum for the outcome of a game
        */
        enum GameOutcome {
            IN_PROGRESS,
            WHITE_WINS,
            BLACK_WINS,
            DRAW
        };

        Color getTurn();
        Board getBoard();
        
        /*
            @brief A function to play a turn
            @param end The end position of the piece
            @return The outcome of the game
        */
        GameOutcome playTurn(ChessPiece* piece, Position end);
};


#endif

