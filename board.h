#pragma once
#include <string>

using std::string;

class TicTacToeBoard {

public:

    // Creates the board as a board filled with " " characters
    TicTacToeBoard();

    // POST: draws the board object as a tic-tac-toe board to the screen
    void drawBoard() const;

    // PARAM: x and y are coords for where to insert, and isPlayer1 is if current player is player1
    // POST: inserts either X or O at cords and returns true, or returns false if coords invalid
    bool insert(int x, int y, bool isPlayer1);

    // PARAM: isPlayer1 is if current player is player1
    // POST: returns true if player1 or player2 won tic tac toe, false otherwise
    bool didPlayerWin(bool isPlayer1) const;

    // PARAM: isPlayer1 is if current player is player1
    // POST: prints to screen the board and a win screen for the current player
    void displayWinScreen(bool isPlayer1) const;

private:
    string board[3][3];

};