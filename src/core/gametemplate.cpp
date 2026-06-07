#include "gametemplate.hpp"
#include <utility>

Board ClassicChessTemplate::getInitialGameState() {
    Board board = Board(8, 8);

    for(int i = 0; i < 8; i++) {
        board.placePiece(new Pawn(Color::WHITE), {1, i});
        board.placePiece(new Pawn(Color::BLACK), {6, i});
    }

    board.placePiece(new Rook(Color::WHITE), {0, 0});
    board.placePiece(new Knight(Color::WHITE), {0, 1});
    board.placePiece(new Bishop(Color::WHITE), {0, 2});
    board.placePiece(new Queen(Color::WHITE), {0, 3});
    board.placePiece(new King(Color::WHITE), {0, 4});
    board.placePiece(new Bishop(Color::WHITE), {0, 5});
    board.placePiece(new Rook(Color::WHITE), {0, 6});
    board.placePiece(new Knight(Color::WHITE), {0, 7});

    board.placePiece(new Rook(Color::BLACK), {7, 0});
    board.placePiece(new Knight(Color::BLACK), {7, 1});
    board.placePiece(new Bishop(Color::BLACK), {7, 2});
    board.placePiece(new Queen(Color::BLACK), {7, 3});
    board.placePiece(new King(Color::BLACK), {7, 4});
    board.placePiece(new Bishop(Color::BLACK), {7, 5});
    board.placePiece(new Rook(Color::BLACK), {7, 6});
    board.placePiece(new Knight(Color::BLACK), {7, 7});

    return board;
}

// TODO: write code that can read a game template from a file (like a json file)
