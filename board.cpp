#include "board.h"
#include <iostream>

using std::cout;

const int ROWS = 3;
const int COLUMNS = 3;

TicTacToeBoard::TicTacToeBoard()
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = " ";
        }
    }
}

void TicTacToeBoard::drawBoard() const
{

    cout << "\n\n";

    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLUMNS; j++) {

            if (j == COLUMNS - 1) {
                cout << board[i][j];
            }
            else {
                cout << board[i][j] << " | ";
            }

        }

        if (i != ROWS - 1) {
            cout << "\n";
            cout << "----------";
            cout << "\n";
        }
    }

    cout << "\n\n";
}

bool TicTacToeBoard::insert(int x, int y, bool isPlayer1)
{
    // check if the coords are in the boundaries of the board
    if (x > 2 || x < 0 || y > 2 || y < 0) {
        return false;
    }

    else if (board[y][x] == "X" || board[y][x] == "O") {
        return false;
    }


    else {
        if (isPlayer1) {
            board[y][x] = "X";
        }
        else {
            board[y][x] = "O";
        }
        return true;
    }

}

bool TicTacToeBoard::didPlayerWin(bool isPlayer1) const
{
    //stub
    return false;
}

void TicTacToeBoard::displayWinScreen(bool isPlayer1) const
{

}