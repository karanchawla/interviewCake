#include <iostream>

using namespace std;

int rand7()
{
	return rand()%7 + 1;
}


int rand5()
{
    int roll = rand7();
    if (roll <= 5) {
        return roll;
    }
    else {
        return rand5();
    }
}