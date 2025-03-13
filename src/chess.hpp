#ifndef CHESS_HPP
#define CHESS_HPP

#include "board.hpp"

class Chess {
    private:
        Board board;
    public:
        Chess();
        void run();
};

#endif