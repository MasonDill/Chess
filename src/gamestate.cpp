#include "gamestate.hpp"

GameState::GameState(int ranks, int files, std::vector<ChessPiece*> pieces) : board(ranks, files, pieces), turn(0), whiteTurn(true) {};
GameState::GameState(GameTemplate* gameTemplate) : GameState(gameTemplate->ranks(), gameTemplate->files(), gameTemplate->getInitialPieces()) {};

Color GameState::getTurn() {
    return whiteTurn ? Color::WHITE : Color::BLACK;
}

GameState::GameOutcome GameState::playTurn(ChessPiece* piece, MoveSequence moveSequence) {
    Position end = piece->position;
    // TODO: implement this
    // for (Move move : moveSequence.moves) {
    //     switch(move.direction) {
    //         case Direction::NORTH:
    //             end.rank += move.distance;
    //             break;
    //         case Direction::SOUTH:
    //             end.rank -= move.distance;
    //             break;
    //         case Direction::EAST:
    //             end.file += move.distance;
    //             break;
    //         case Direction::WEST:
    //             end.file -= move.distance;
    //             break;
    // }

    board.movePiece(piece, end);

    // TODO: check for checkmate/draw

    return GameState::GameOutcome::IN_PROGRESS;
}
