#include <iostream>
#include <cstdlib>

using namespace std;

int rand5()
{
	return rand()%5 + 1;
}

int rand7Table()
{
    const int results[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 1, 2, 3},
        {4, 5, 6, 7, 1},
        {2, 3, 4, 5, 6},
        {7, 0, 0, 0, 0}
    };

    while (true) {

        // do our die rolls
        int row = rand5() - 1;
        int column = rand5() - 1;

        // case: we hit an extraneous outcome
        // so we need to re-roll
        if (row == 4 && column > 0) {
            continue;
        }

        // our outcome was fine. return it!
        return results[row][column];
    }
}