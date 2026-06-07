#ifndef GAMETEMPLATE_HPP
#define GAMETEMPLATE_HPP

#include <utility>
#include "piece.hpp"
#include "board.hpp"

/*
    @class GameTemplate
    @brief A class to define preset game setups
*/
class GameTemplate {
    public:
        virtual Board getInitialGameState() = 0;
};

/*
    @class ClassicChess
    @brief A template for the classic chess setup
*/
class ClassicChessTemplate : public GameTemplate {
    public:
        Board getInitialGameState() override;
};

#endif
