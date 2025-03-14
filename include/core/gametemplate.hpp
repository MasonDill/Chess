#ifndef GAMETEMPLATE_HPP
#define GAMETEMPLATE_HPP

#include <utility>
#include "piece.hpp"

/*
    @class GameTemplate
    @brief A class to define preset game setups
*/
class GameTemplate {
    public:
        virtual std::vector<ChessPiece*> getInitialPieces() = 0;
        virtual int ranks() = 0;
        virtual int files() = 0;

        std::pair<std::vector<ChessPiece*>, std::pair<int, int>> getInitialState() {
            return std::make_pair(getInitialPieces(), std::make_pair(ranks(), files()));
        }
};

/*
    @class ClassicChess
    @brief A template for the classic chess setup
*/
class ClassicChess : public GameTemplate {
    public:
        std::vector<ChessPiece*> getInitialPieces() override;
        int ranks() override;
        int files() override;
};

#endif
