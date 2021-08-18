#include "board.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;

int main()
{
    bool gameLoop = true;
    cout << "Welcome to 2-player Tic Tac Toe! Do you wish to (p)lay or (q)uit? ";

    while (gameLoop) {

        string playOrQuit = "";
        cin >> playOrQuit;

        while (playOrQuit != "p" && playOrQuit != "q") {
            cout << "Please type a valid response: ";
            cin >> playOrQuit;
        }

        if (playOrQuit == "q") {
            gameLoop = false;
        }

        bool isPlayer1 = true;
        TicTacToeBoard board;

        // turn loop
        while (playOrQuit == "p") {

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
                    playOrQuit = "q"; // leave turn loop

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

                }
            }

            // switches to other player for next turn loop
            isPlayer1 = !isPlayer1;
        }
    }

    return 0;
}