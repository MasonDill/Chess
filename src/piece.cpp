#include "piece.hpp"
#include "move.hpp"

/*
    @brief Returns whether the move is legal
    @param endPos The position to move to
    @return True if the move is legal, false otherwise
    @details uses the move.hpp function to check if the move is legal
*/
bool ChessPiece::isLegalMove(Position endPos) {
    return ::canReachDestination(this->position, endPos, this->movePattern);
}
