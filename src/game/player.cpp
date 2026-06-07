#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "player.hpp"
#include "console.hpp"

#define HELP_KEYWORD "help"

/*** Helper functions ***/

// Commands (typed alone) that request to quit the game. Edit this list to
// change the accepted quit keywords - matching and help text follow it.
static const std::vector<std::string> EXIT_COMMANDS = {"exit", "quit", "q"};

static bool isExitCommand(const std::string& input){
    for (const std::string& command : EXIT_COMMANDS) {
        if (input == command) {
            return true;
        }
    }
    return false;
}

// Render the exit commands as a "exit / quit / q" list for help text.
static std::string exitCommandList(){
    std::string list;
    for (size_t i = 0; i < EXIT_COMMANDS.size(); i++) {
        if (i > 0) {
            list += " / ";
        }
        list += EXIT_COMMANDS[i];
    }
    return list;
}

static std::string promptUserInput(Color color){
    std::string colorString = color == Color::WHITE ? "White" : "Black";
    std::cout << colorString << " player, enter your move (type '"
              << HELP_KEYWORD << "' for instructions): ";

    std::string playerInput;
    if (!std::getline(std::cin, playerInput)) {
        // End-of-input (e.g. piped input or Ctrl-D): treat as exit so we
        // don't spin forever re-prompting on a closed stream.
        throw ExitGameException("\nNo more input - exiting game.");
    }
    return playerInput;
}

static std::string getHelpMessage(){
    std::string helpMessage = "--------------------------------\n";
    helpMessage += "HOW TO ENTER A MOVE\n\n";

    helpMessage += "Format: <piece><from><to>   (no spaces)\n";
    helpMessage += "  <piece>  one of: p r n b q k  (pawn, rook, knight, bishop, queen, king)\n";
    helpMessage += "  <from>   the square the piece is on\n";
    helpMessage += "  <to>     the square to move it to\n\n";

    helpMessage += "Squares are a file (column a-h) followed by a rank (row 1-8).\n";
    helpMessage += "Example: pe2e4  ->  move the pawn on e2 to e4\n";
    helpMessage += "Example: ng1f3  ->  move the knight on g1 to f3\n\n";

    helpMessage += "Other commands:\n";
    helpMessage += "  " HELP_KEYWORD "  show this message again\n";
    helpMessage += "  " + exitCommandList() + "  quit the game\n";

    helpMessage += "--------------------------------\n";
    return helpMessage;
}

// Ask the user to confirm quitting. Defaults to "no" so a stray quit
// command (or just hitting enter) keeps the game going.
static bool confirmQuit(){
    std::cout << "Are you sure you would like to quit (y/N)? ";

    std::string response;
    if (!std::getline(std::cin, response)) {
        return true; // no more input -> let the game end
    }
    return response == "y" || response == "Y";
}

static std::string invalidMoveMessage(){
    std::string invalidMoveMessage = "Invalid move notation - expected format: <piece><from><to> (e.g. pe2e4)\n";
    invalidMoveMessage += "type '" HELP_KEYWORD "' for instructions\n";
    return invalidMoveMessage;
}

static std::pair<PieceType, std::pair<Position, Position>> readPlayerInput(Color color, Board& board){
    std::regex notationRegex("^[prnbqk][a-h][1-8][a-h][1-8]$");

    std::string playerInput;
    while (true) {
        // The player can't choose a move without seeing the board, so show it
        // before every prompt (including help/empty/declined-quit re-prompts).
        board.printBoard();
        playerInput = promptUserInput(color);

        if (playerInput.empty()) {
            // Empty input: wipe the clutter and show the menu again.
            clearScreen();
            std::cout << getHelpMessage();
            continue;
        }

        if (isExitCommand(playerInput)) {
            if (confirmQuit()) {
                throw ExitGameException("Thanks for playing!");
            }
            continue; // user changed their mind; ask for a move again
        }

        if (playerInput == HELP_KEYWORD) {
            // Show help and re-prompt in place, without counting as a bad move.
            std::cout << getHelpMessage();
            continue;
        }

        if (!std::regex_match(playerInput, notationRegex)) {
            throw InvalidInputException(invalidMoveMessage());
        }

        break; // valid notation
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
std::pair<ChessPiece*, Position> Player::queryPlayerMove(Board& board){
    std::pair<PieceType, std::pair<Position, Position>> playerInput = readPlayerInput(this->color, board);
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
    if (!pieceToMove->isLegalMove(startPos, endPos)) {
        throw std::invalid_argument("Selected illegal move");
    }

    return std::make_pair(pieceToMove, endPos);
}