#include <vector> 
#include <iostream>

using namespace std;

int fib(int n)
{
    // edge cases:
    if (n < 0) 
    {
        throw invalid_argument(
            "Index was negative.");
    }
    else if (n == 0 || n == 1) 
    {
        return n;
    }

    int prevPrev = 0;   // 0th fibonacci
    int prev = 1;       // 1st fibonacci
    int current = 0;    // Declare and initialize current

    for (int i = 1; i < n; ++i) 
    {
        current = prev + prevPrev;
        prevPrev = prev;
        prev = current;
    }

    return current;
}