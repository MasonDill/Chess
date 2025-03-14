#include "gametemplate.hpp"
#include <utility>

int ClassicChess::ranks() {
    return 8;
}

int ClassicChess::files() {
    return 8;
}

std::vector<ChessPiece*> ClassicChess::getInitialPieces() {
    std::vector<ChessPiece*> pieces;

    PieceType pieceFiles[8] = {
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING,
        BISHOP,
        KNIGHT,
        ROOK
    };

    for (int i = 0; i < 8; i++) {
        Position p;
        p.rank = 1;
        p.file = i;
        struct Position p2 = {1, i};

        pieces.push_back(new Pawn(WHITE, Position{1, i}));
        pieces.push_back(new Pawn(BLACK, Position{6, i}));

        switch (pieceFiles[i]) {
            case ROOK:
                pieces.push_back(new Rook(WHITE, Position{0, i}));
                pieces.push_back(new Rook(BLACK, Position{7, i}));
                break;
            case KNIGHT:
                pieces.push_back(new Knight(WHITE, Position{0, i}));
                pieces.push_back(new Knight(BLACK, Position{7, i}));
                break;
            case BISHOP:
                pieces.push_back(new Bishop(WHITE, Position{0, i}));
                pieces.push_back(new Bishop(BLACK, Position{7, i}));
                break;
            case QUEEN:
                pieces.push_back(new Queen(WHITE, Position{0, i}));
                pieces.push_back(new Queen(BLACK, Position{7, i}));
                break;
            case KING:
                pieces.push_back(new King(WHITE, Position{0, i}));
                pieces.push_back(new King(BLACK, Position{7, i}));
                break;
        }
    }

    return pieces;
}

// TODO: write code that can read a game template from a file (like a json file)
