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
    int WIN_CONDITION = 3;

    // check if 3 symbols in a row horizontally
    for (int i = 0; i < ROWS; i++) {
        int amountOfSymbols = 0; // reps amount "X" or "O" depending on isPlayer1

        for (int j = 0; j < COLUMNS; j++) {

            if (board[i][j] == "X" && isPlayer1) {
                amountOfSymbols++;
            }
            else if (board[i][j] == "O" && !isPlayer1) {
                amountOfSymbols++;
            }
        }

        if (amountOfSymbols == WIN_CONDITION) {
            return true;
        }
    }

    // check if 3 symbols in a row vertically
    for (int i = 0; i < COLUMNS; i++) {
        int amountOfSymbols = 0; // reps amount "X" or "O" depending on isPlayer1

        for (int j = 0; j < ROWS; j++) {

            if (board[j][i] == "X" && isPlayer1) {
                amountOfSymbols++;
            }
            else if (board[j][i] == "O" && !isPlayer1) {
                amountOfSymbols++;
            }
        }

        if (amountOfSymbols == WIN_CONDITION) {
            return true;
        }
    }

    // check if 3 symbols in a row diagonally (only 2 cases)
    if (isPlayer1) {

        if (board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X") {
            return true;
        }
        else if (board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "X") {
            return true;
        }
    }
    else {

        if (board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O") {
            return true;
        }
        else if (board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "O") {
            return true;
        }
    }

    return false;
}

void TicTacToeBoard::displayWinScreen(bool isPlayer1) const
{
    string player = "";
    if (isPlayer1) {
        player = "Player1";
    }
    else {
        player = "Player2";
    }

    drawBoard();
    cout << player << " has won!!\n\n";
    cout << "Do you want to play again? Type 'p' to play, type 'q' to quit: ";
}