#include <vector> 
#include <algorithm>
#include <iostream>
#include <random>

using namespace std; 

void inPlaceShuffle(vector<int> &nums)
{
	for(int i = 0; i < nums.size(); i++)
	{
		int index = getRandom(i, nums.size() - 1);
		swap(nums[i], nums[index]);
	}

	return;
}