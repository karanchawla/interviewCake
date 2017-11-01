#include <iostream> 
#include <vector>
#include <algorithm> 

using namespace std;

int findNumber(vector<int> &nums, int n)
{
	int sum = n*(n+1)/2;
	int sumOfNums = accumulate(nums.begin(), nums.end(), 0);

	return sum - sumOfNums;
}