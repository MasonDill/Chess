#include "gamestate.hpp"

GameState::GameState(int ranks, int files, std::vector<ChessPiece*> pieces) : board(ranks, files, pieces) {
    this->board = Board(ranks, files, pieces);
    this->turn = 0;
    this->whiteTurn = true;
}
