#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <stdexcept>
#include "piece.hpp"

class Board {
    private:
        ChessPiece*** board;

        void populateBoard(std::vector<ChessPiece*> pieces) {
            for (int i = 0; i < pieces.size(); i++) {
                int rank = pieces[i]->getPosition().rank;
                int file = pieces[i]->getPosition().file;

                if (board[rank][file] != nullptr) {
                    throw std::invalid_argument("Cannot populate board with piece at position already occupied");
                }
                
                board[rank][file] = pieces[i];
            }
        }

    public:
        int ranks;
        int files;

        Board(int ranks, int files) : ranks(ranks), files(files) {
            board = new ChessPiece**[ranks];
            for (int i = 0; i < ranks; i++) {
                board[i] = new ChessPiece*[files]();
                for (int j = 0; j < files; j++) {
                    board[i][j] = NULL;
                }
            }
        }

        Board(int ranks, int files, std::vector<ChessPiece*> pieces) : ranks(ranks), files(files) {
            Board(ranks, files);
            this->populateBoard(pieces);
        }

        ~Board() {
            for (int i = 0; i < ranks; i++) {
                free(board[i]);
            }
            free(board);
        }

        void movePiece(ChessPiece* piece, Position end) {
            ChessPiece* target = board[end.rank][end.file];

            if (target != nullptr) {
                if (target->getColor() == piece->getColor()) {
                    throw std::invalid_argument("Cannot move piece to position occupied by friendly piece");
                }
            }

            target = piece;
            piece = nullptr;
        }
};

#endif
