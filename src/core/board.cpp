#include <iostream>
#include "board.hpp"

/*** Helper functions ***/

// static void populateBoard(ChessPiece*** board, std::vector<ChessPiece*> pieces) {
//     for (int i = 0; i < pieces.size(); i++) {
//         int rank = pieces[i]->position.rank;
//         int file = pieces[i]->position.file;
//         if (board[rank][file] != nullptr) {
//             throw std::invalid_argument("Cannot populate board with piece at position already occupied");
//         }
        
//         board[rank][file] = pieces[i];
//     }
// }

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

// Board::Board(int ranks, int files, std::vector<ChessPiece*> pieces) : Board(ranks, files) {
//     populateBoard(this->board, pieces);
// }

Board::~Board() {
    if (board == nullptr) {
        return; // moved-from board owns nothing
    }
    for (int i = 0; i < ranks; i++) {
        delete[] board[i];
    }
    delete[] board;
}

Board::Board(Board&& other) noexcept
    : board(other.board), ranks(other.ranks), files(other.files) {
    other.board = nullptr;
    other.ranks = 0;
    other.files = 0;
}

Board& Board::operator=(Board&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    // free our existing storage
    if (board != nullptr) {
        for (int i = 0; i < ranks; i++) {
            delete[] board[i];
        }
        delete[] board;
    }

    board = other.board;
    ranks = other.ranks;
    files = other.files;

    other.board = nullptr;
    other.ranks = 0;
    other.files = 0;

    return *this;
}

ChessPiece* Board::getPiece(Position pos) {
    if (!isInBounds(pos)) {
        throw std::invalid_argument("Position out of bounds");
    }
    return board[pos.rank][pos.file];
}

void Board::placePiece(ChessPiece* piece, Position pos) {
    if (!isInBounds(pos)) {
        throw std::invalid_argument("Position out of bounds");
    }

    ChessPiece* target = board[pos.rank][pos.file];

    if (target != nullptr) {
        if (target->getColor() == piece->getColor()) {
            throw std::invalid_argument("Cannot move piece to position occupied by friendly piece");
        }
        delete target; // cleanup any pieces that were captured
    }

    board[pos.rank][pos.file] = piece;
}

std::vector<ChessPiece*> Board::getPieces(Color color, PieceType type) {
    std::vector<ChessPiece*> pieces;
    for (int i = 0; i < ranks; i++) {
        for (int j = 0; j < files; j++) {
            if (board[i][j] == nullptr) {
                continue;
            }
            
            if (board[i][j]->getColor() == color & board[i][j]->getType() == type) {
                pieces.push_back(board[i][j]);
            }
        }
    }
    return pieces;
}

std::vector<ChessPiece*> Board::getPieces(Color color) {
    return getPieces(color, PieceType::ANY);
}

std::vector<ChessPiece*> Board::getPieces(PieceType type) {
    return getPieces(Color::GRAY, type);
}

std::vector<ChessPiece*> Board::getPieces() {
    return getPieces(Color::GRAY, PieceType::ANY);
}

void Board::printBoard() {
    // print the files
    std::cout << "\t";
    for(int i = 0; i < files; i++) {
        std::cout << (char)('a' + i) << "\t";
    }
    std::cout << std::endl;

    for (int i = 0; i < ranks; i++) {
        std::cout << i + 1 << "\t"; // print the rank

        for (int j = 0; j < files; j++) {
            if (board[i][j] == nullptr) {
                std::cout << ".";
            } else {
                std::cout << board[i][j]->displayPiece();
            }
            std::cout << "\t";
        }
        std::cout << std::endl;
    }
}

bool Board::isInBounds(int rank, int file) {
    return rank >= 0 && rank < ranks && file >= 0 && file < files;
}

bool Board::isInBounds(Position pos) {
    return isInBounds(pos.rank, pos.file);
}
