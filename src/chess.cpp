#include <vector>
#include "chess.hpp"

#include <iostream>

void Chess::play() {
    Player whitePlayer = Player(true);
    Player blackPlayer = Player(false);

    GameState::GameOutcome outcome;
    do{
        ChessPiece* piece;
        Position end;
        switch(gameState->getTurn()) {
            case Color::WHITE:
                std::tie(piece, end) = whitePlayer.queryPlayerMove(gameState->getBoard());
                break;
            case Color::BLACK:
                std::tie(piece, end) = blackPlayer.queryPlayerMove(gameState->getBoard());
                break;
            default:
                throw std::invalid_argument("Invalid turn");
        }

        outcome = gameState->playTurn(piece, end);
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