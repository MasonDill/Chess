#ifndef GAMETEMPLATE_HPP
#define GAMETEMPLATE_HPP

#include <utility>
#include "gamestate.hpp"

class GameTemplate {
    public:
        virtual std::vector<ChessPiece*> getInitialPieces() = 0;
        virtual int ranks() = 0;
        virtual int files() = 0;

        std::pair<std::vector<ChessPiece*>, std::pair<int, int>> getInitialState() {
            return std::make_pair(getInitialPieces(), std::make_pair(ranks(), files()));
        }
};

class ClassicChess : public GameTemplate {
    public:
        std::vector<ChessPiece*> getInitialPieces() override;
        int ranks() override;
        int files() override;
};

#endif
