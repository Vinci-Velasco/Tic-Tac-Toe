// test file that tests TicTacToeBoard class
// compile this and run its excutable whenever you need test cases done
#include "board.h"
#include <cassert>

void insertTest();
void didPlayerWin();

int main()
{
    insertTest();
    didPlayerWin();
    return 0;
}

void insertTest()
{
    TicTacToeBoard board1;

    // insert at empty board
    assert(board1.insert(0,0, true));

    // insert out of bounds
    assert(!board1.insert(-1,5, true));

    // insert on board not empty
    assert(board1.insert(1,0, true));
    assert(board1.insert(1,1, true));
    assert(board1.insert(2,2, false));

    // insert on spot that current player already filled
    assert(!board1.insert(0,0, true));

    // insert on spot that other player already filled
    assert(!board1.insert(2,2, false));

}

void didPlayerWin()
{
    TicTacToeBoard board1;

    // check when win condition is false (empty board)
    assert(!board1.didPlayerWin(true));
    assert(!board1.didPlayerWin(false));

    // check when win condition is false (not empty)
    board1.insert(0, 0, true);
    board1.insert(1, 1, false);
    board1.insert(2, 2, true);
    board1.insert(1, 0, false);

    assert(!board1.didPlayerWin(true));
    assert(!board1.didPlayerWin(false));

    // check when vertical 3 in a row
    board1.insert(1, 2, false);
    assert(!board1.didPlayerWin(true));
    assert(board1.didPlayerWin(false));

    // check when horizontal 3 in a row
    TicTacToeBoard board2;
    board2.insert(0, 0, true);
    board2.insert(2, 1, false);
    board2.insert(1, 0, true);
    board2.insert(2, 0, true);
    assert(board2.didPlayerWin(true));
    assert(!board2.didPlayerWin(false));

    // check when diagonal 3 in a row
    board2.insert(1, 1, true);
    board2.insert(0, 2, true);
    assert(board2.didPlayerWin(true));
    assert(!board2.didPlayerWin(false));
}