#pragma once
#include <string>

using std::string;

class TicTacToeBoard {

public:
    // POST: draws the board object as a tic-tac-toe board to the screen
    void drawBoard();

    // PARAM: x and y are coords for where to insert, and isPlayer1 is if current player is player1
    // POST: inserts either X or O at cords and returns true, or returns false if coords invalid
    bool insert(int x, int y, bool isPlayerOne);

    // PARAM: isPlayer1 is if current player is player1
    // POST: returns true if player1 or player2 won tic tac toe, false otherwise
    bool didPlayerWin(bool isPlayerOne);

private:
    string board[3][3];

};