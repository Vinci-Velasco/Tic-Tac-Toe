// test file that tests TicTacToeBoard class
// compile this and run its excutable whenever you need test cases done
#include "board.h"
#include <cassert>

void insert_test();

int main()
{

    insert_test();
    return 0;
}

void insert_test()
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