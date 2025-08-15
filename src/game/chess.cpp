#include <vector>
#include <exception>

#include "chess.hpp"
#include "player.hpp"

#include <iostream>
#include <cassert>

void Chess::play() {
    Player whitePlayer = Player(Color::WHITE);
    Player blackPlayer = Player(Color::BLACK);

    GameState::GameOutcome outcome;
    do{
        ChessPiece* piece;
        Position end;

        // Retry this logic if an exception occurs
        bool moveSelected = false;
        while (!moveSelected) {
            try {
                gameState->getBoard().printBoard();
                switch(gameState->getTurn()) {
                    case Color::WHITE:
                        std::tie(piece, end) = whitePlayer.queryPlayerMove(gameState->getBoard());
                        break;
                    case Color::BLACK:
                        std::tie(piece, end) = blackPlayer.queryPlayerMove(gameState->getBoard());
                        break;
                    // default:
                    //     assert(false); // should never happen
                }
                moveSelected = true;
            }
            catch (const InvalidInputException& e) {
                std::cout << "CAUGHT EXCEPTION" << std::endl;
            }
            catch (const ExitGameException& e) {
                std::cout << e.what() << std::endl;
                //return;
            }
            catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
            }
        }
        // clear the console
        system("cls");

        outcome = gameState->playTurn(piece, end);
    } while (outcome == GameState::GameOutcome::IN_PROGRESS);

    switch(outcome) {
        case GameState::GameOutcome::WHITE_WINS:
            std::cout << "White wins!" << std::endl;
            break;
        case GameState::GameOutcome::BLACK_WINS:
            std::cout << "Black wins!" << std::endl;
            break;
        case GameState::GameOutcome::DRAW:
            std::cout << "Draw!" << std::endl;
            break;
        default:
            throw std::invalid_argument("Invalid outcome");
    }
}