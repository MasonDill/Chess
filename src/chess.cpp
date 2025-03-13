#include <vector>
#include "chess.hpp"

#include <iostream>

void Chess::run() {
    Player whitePlayer = Player(true);
    Player blackPlayer = Player(false);

    GameState::GameOutcome outcome;
    do{
        ChessPiece* piece;
        MoveSequence moveSequence;
        switch(gameState->getTurn()) {
            case Color::WHITE:
                std::tie(piece, moveSequence) = whitePlayer.queryPlayerMove(*gameState);
                break;
            case Color::BLACK:
                std::tie(piece, moveSequence) = blackPlayer.queryPlayerMove(*gameState);
                break;
            default:
                throw std::invalid_argument("Invalid turn");
        }

        outcome = gameState->playTurn(piece, moveSequence);
    } while (outcome == GameState::GameOutcome::IN_PROGRESS);

    // switch(outcome) {
    //     case GameState::GameOutcome::WHITE_WINS:
    //         std::cout << "White wins!" << std::endl;
    //         break;
    //     case GameState::GameOutcome::BLACK_WINS:
    //         std::cout << "Black wins!" << std::endl;
    //         break;
    //     case GameState::GameOutcome::DRAW:
    //         std::cout << "Draw!" << std::endl;
    //         break;
    //     default:
    //         throw std::invalid_argument("Invalid outcome");
    // }
}