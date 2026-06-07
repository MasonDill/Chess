#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <iostream>

/*
    @brief ANSI escape sequence that clears the screen and moves the cursor
    to the home position. Works on macOS/Linux terminals and Windows Terminal.
*/
constexpr const char* CLEAR_SCREEN = "\033[2J\033[H";

/* @brief Clear the console screen. */
inline void clearScreen() {
    std::cout << CLEAR_SCREEN;
}

#endif
