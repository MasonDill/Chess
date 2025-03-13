#include "player.hpp"

std::pair<ChessPiece*, Position> Player::queryPlayerMove(Board board){
    /* @TODO: queryPlayerMove()*/
    std::vector<ChessPiece*> myPieces = board.getPieces(this->color);

    // Ask the player to select a piece
    ChessPiece* pieceToMove = myPieces[0];

    // Give the player the piece's possible moves
    std::vector<Position> moves = getMoveDestinations(pieceToMove->position, pieceToMove->getMovePattern());

    // Ask the player to select a move
    Position move = moves[0];

    return std::make_pair(pieceToMove, move);
}