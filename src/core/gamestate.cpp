#include "gamestate.hpp"

GameState::GameState(GameTemplate* gameTemplate) : board(gameTemplate->getInitialGameState()), turn(0), whiteTurn(true) {}

Color GameState::getTurn() {
    return whiteTurn ? Color::WHITE : Color::BLACK;
}

Board& GameState::getBoard() {
    return board;
}

GameState::GameOutcome GameState::playTurn(ChessPiece* piece, Position end) {
    board.placePiece(piece, end);

    // TODO: check for checkmate/stalemate
        

    // Update 
    turn++;
    whiteTurn = !whiteTurn;

    return GameState::GameOutcome::IN_PROGRESS;
}
