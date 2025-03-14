#include "gamestate.hpp"

GameState::GameState(int ranks, int files, std::vector<ChessPiece*> pieces) : board(ranks, files, pieces), turn(0), whiteTurn(true) {};
GameState::GameState(GameTemplate* gameTemplate) : GameState(gameTemplate->ranks(), gameTemplate->files(), gameTemplate->getInitialPieces()) {};

Color GameState::getTurn() {
    return whiteTurn ? Color::WHITE : Color::BLACK;
}

Board GameState::getBoard() {
    return board;
}

GameState::GameOutcome GameState::playTurn(ChessPiece* piece, Position end) {
    board.movePiece(piece, end);

    // TODO: check for checkmate/draw


    // Update 
    turn++;
    whiteTurn = !whiteTurn;

    return GameState::GameOutcome::IN_PROGRESS;
}
