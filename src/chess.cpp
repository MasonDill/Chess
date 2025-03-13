#include <vector>
#include "chess.hpp"

#include <iostream>

Chess::Chess() : board(8, 8) {
    std::vector<ChessPiece*> pieces;

    for (int i = 0; i < 8; i++) {
        Position p;
        p.rank = 1;
        p.file = i;
        struct Position p2 = {1, i};

        Pawn pa = Pawn(WHITE, p2);
        pieces.push_back(new Pawn(WHITE, Position{1, i}));
    }

    board = Board(8, 8, pieces);
}

void Chess::run() {
    // TODO: Implement the game loop
    std::cout << "Chess game started" << std::endl;
}
