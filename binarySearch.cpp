#include <iostream>
#include <vector> 

using namespace std; 

bool binarySearch(const vector<int> &nums, int target)
{
	int floorIndex = 0;
	int ceilIndex = nums.size() - 1;

	while(floorIndex < ceilIndex)
	{
		int middleIndex = floorIndex + (ceilIndex - floorIndex)/2;

		int guessValue = nums[middleIndex];

		if(guessValue == target)
			return true;

		if(guessValue > target)
			ceilIndex = middleIndex;

		else if(guessValue < target)
			floorIndex = middleIndex + 1;
	}

	return false;
}