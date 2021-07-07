#include "board.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;

int main()
{

    cout << "Welcome to 2-player Tic Tac Toe! Do you wish to (p)lay or (q)uit? ";
    string playOrQuit = "";
    cin >> playOrQuit;

    bool gameLoop = true;

    while (gameLoop) {

        while (playOrQuit != "p" && playOrQuit != "q") {
            cout << "Please type a valid response: ";
            cin >> playOrQuit;
        }

        // game loop
        while (playOrQuit == "p") {

            bool isPlayer1 = true;
            TicTacToeBoard board;
            board.drawBoard();

            if (isPlayer1) {

                int x = 0;
                int y = 0;

                cout << "Player 1 input your x-coord: ";
                cin >> x;
                cout << "Player 1 input your y-coord: ";
                cin >> y;

                while (!board.insert(x, y, isPlayer1)) {

                    cout << "Please enter valid coordinates.\n";
                    cout << "Player One input your x-coord: ";
                    cin >> x;
                    cout << "Player One input your y-coord: ";
                    cin >> y;
                }

                if (board.didPlayerWin(isPlayer1)) {

                    board.displayWinScreen(isPlayer1);
                    cin >> playOrQuit;

                    if (playOrQuit == "q") {
                        gameLoop = false;
                    }

                }
            }

            else {

                int x = 0;
                int y = 0;

                cout << "Player 2 input your x-coord: ";
                cin >> x;
                cout << "Player 2 input your y-coord: ";
                cin >> y;

                while (!board.insert(x, y, isPlayer1)) {

                    cout << "Please enter valid coordinates.\n";
                    cout << "Player 2 input your x-coord: ";
                    cin >> x;
                    cout << "Player 2 input your y-coord: ";
                    cin >> y;
                }

                if (board.didPlayerWin(isPlayer1)) {

                    board.displayWinScreen(isPlayer1);
                    cin >> playOrQuit;

                    if (playOrQuit == "q") {
                        gameLoop = false;
                    }

                }
            }

            // switches to opposite boolean value
            isPlayer1 = !isPlayer1;
        }
    }

    // keep track of who's current player
    // loop: draw board, take input, insert to board, check win condition,
    // repeat until game is over
    return 0;
}