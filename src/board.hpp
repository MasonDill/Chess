#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <stdexcept>
#include "piece.hpp"

/*
    @class Board
    @brief A class for the board of a chess game
*/
class Board {
    private:
        /*
            @brief The board of the chess game
            @note 2D array of pointers to ChessPiece objects
        */
        ChessPiece*** board;
        /*
            @brief The number of ranks on the board
        */
        int ranks;

        /*
            @brief The number of files on the board
        */
        int files;

    public:

        Board(int ranks, int files);
        Board(int ranks, int files, std::vector<ChessPiece*> pieces);
        ~Board();

        int getRanks();
        int getFiles();
        ChessPiece* getPiece(int rank, int file);
        std::vector<ChessPiece*> getPieces();
        std::vector<ChessPiece*> getPieces(Color color);

        /*
            @brief Move a piece from a position to another
            @param piece The piece to move
            @param end The position to move the piece to
        */
        void movePiece(ChessPiece* piece, Position end);
};

#endif
