#include "board.hpp"

/*** Helper functions ***/

static void populateBoard(ChessPiece*** board, std::vector<ChessPiece*> pieces) {
    for (int i = 0; i < pieces.size(); i++) {
        int rank = pieces[i]->position.rank;
        int file = pieces[i]->position.file;
        if (board[rank][file] != nullptr) {
            throw std::invalid_argument("Cannot populate board with piece at position already occupied");
        }
        
        board[rank][file] = pieces[i];
    }
}

/*** Board member functions ***/

Board::Board(int ranks, int files) : ranks(ranks), files(files) {
    board = new ChessPiece**[ranks];
    for (int i = 0; i < ranks; i++) {
        board[i] = new ChessPiece*[files]();
        for (int j = 0; j < files; j++) {
            board[i][j] = NULL;
        }
    }
}

Board::Board(int ranks, int files, std::vector<ChessPiece*> pieces) : Board(ranks, files) {
    populateBoard(this->board, pieces);
}

Board::~Board() {
    for (int i = 0; i < ranks; i++) {
        delete[] board[i];
    }
    delete[] board;
}

void Board::movePiece(ChessPiece* piece, Position end) {
    ChessPiece* target = board[end.rank][end.file];

    if (target != nullptr) {
        if (target->getColor() == piece->getColor()) {
            throw std::invalid_argument("Cannot move piece to position occupied by friendly piece");
        }
    }

    ChessPiece* temp = target;

    target = piece;
    piece = nullptr;

    if (temp != nullptr) {
        delete temp; // cleanup any pieces that were captured
    }
}

std::vector<ChessPiece*> Board::getPieces(Color color) {
    std::vector<ChessPiece*> pieces;
    for (int i = 0; i < ranks; i++) {
        for (int j = 0; j < files; j++) {
            if (board[i][j] != nullptr && board[i][j]->getColor() & color > 0) {
                pieces.push_back(board[i][j]);
            }
        }
    }
    return pieces;
}

std::vector<ChessPiece*> Board::getPieces() {
    return getPieces(Color::GRAY);
}
