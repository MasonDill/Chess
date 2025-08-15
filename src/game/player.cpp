#include <iostream>
#include <regex>

#include "player.hpp"

#define HELP_KEYWORD "help"
#define EXIT_KEYWORD "exit"

/*** Helper functions ***/

static std::string promptUserInput(Color color){
    std::string playerInput = "";

    std::string colorString = color == Color::WHITE ? "White" : "Black";
    std::cout << colorString << " player, enter your move: ";
    std::cin >> playerInput;
    return playerInput;
}

static std::string getHelpMessage(){
    std::string helpMessage = "--------------------------------\n";
    helpMessage += "Piece types: p, r, n, b, q, k\n";
    helpMessage += "Row and column notation: a-h, 1-8\n\n";

    helpMessage += "Move notation: <piece><start><end>\n";
    helpMessage += "Example: pe2e4 -> Move the piece at e2 to e4\n\n";

    helpMessage += "type 'exit' to exit the game\n\n";
    helpMessage += "type 'help' to display this message again\n\n";

    helpMessage += "--------------------------------\n";
    return helpMessage;
}

static std::string invalidMoveMessage(){
    std::string invalidMoveMessage = "Invalid move notation - expected format: <piece><start><end>\n";
    invalidMoveMessage += "type 'help' for more information\n";
    return invalidMoveMessage;
}

static std::pair<PieceType, std::pair<Position, Position>> readPlayerInput(Color color){
    std::string playerInput = promptUserInput(color);

    std::regex notationRegex("^[prnbqk][a-h][1-8][a-h][1-8]$");
    if(!std::regex_match(playerInput, notationRegex)) {
        std::cout << "Invalid move\n";
        if(playerInput == EXIT_KEYWORD) {
            //throw ExitGameException("Exiting game");
            throw std::invalid_argument("Exiting game");
        }
        else if(playerInput == HELP_KEYWORD) {
            //throw InvalidInputException("test");
            throw std::invalid_argument("Invalid input");
        }
        else{
            //throw InvalidInputException("test");
            throw std::invalid_argument("Invalid input");
        }
    }

    // parse the player input
    PieceType pieceType = ChessPiece::getPieceType(playerInput[0]);
    int startFile = playerInput[1] - 'a';
    int startRank = playerInput[2] - '0';
    int endFile = playerInput[3] - 'a';
    int endRank = playerInput[4] - '0';

    Position startPos = Position{startFile, startRank};
    Position endPos = Position{endFile, endRank};

    return std::make_pair(pieceType, std::make_pair(startPos, endPos));
}

/*** Player member functions ***/

    /*
    @brief Query the player for a move
    @param board The board to query
    @return A pair of the piece to move and the position to move it to

    @details Player provides notation as <piece><start><end>
    @example pe2e4 -> Move the piece at e2 to e4
    
    @todo generalize this to any board dimensions and piece types
*/
std::pair<ChessPiece*, Position> Player::queryPlayerMove(Board board){
    std::pair<PieceType, std::pair<Position, Position>> playerInput = readPlayerInput(this->color);
    PieceType pieceType = playerInput.first;
    Position startPos = playerInput.second.first;
    Position endPos = playerInput.second.second;

    if (!board.isInBounds(startPos)) {
        throw std::invalid_argument("Start position out of bounds");
    }

    if (!board.isInBounds(endPos)) {
        throw std::invalid_argument("End position out of bounds");
    }

    ChessPiece* pieceToMove = board.getPiece(startPos);

    // check that they correctly identified their own piece
    if (pieceToMove == nullptr) {
        throw std::invalid_argument("Did not identify own piece");
    }
    if (pieceToMove->getColor() != this->color) {
        throw std::invalid_argument("Selected invalid piece color");
    }

    // check that the piece is of the correct type
    if (pieceToMove->getType() != pieceType) {
        throw std::invalid_argument("Selected wrong piece type - expected");
    }

    // check that the move is legal
    if (!pieceToMove->isLegalMove(endPos)) {
        throw std::invalid_argument("Selected illegal move");
    }

    return std::make_pair(pieceToMove, endPos);
}