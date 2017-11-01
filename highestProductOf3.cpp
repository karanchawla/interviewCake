#include <iostream>
#include <vector> 
#include <cstdlib>
#include <algorithm>

using namespace std; 

int highestProductOf3(const vector<int> &nums)
{
	if(nums.size() < 3)
		throw invalid_argument("Size of the input vector must be at least 3");


	int highest = nums[0];
	int lowest = nums[0];

	int highestProductOf2 = nums[0]*nums[1];
	int lowestProductOf2 = nums[0]*nums[1];

	int highestProductOf3 = nums[0]*nums[1]*nums[2];
	int lowestProductOf3 = nums[0]*nums[1]*nums[2];

	for(size_t i = 3; i < nums.size(); i++)
	{
		int currentNumber = nums[i];

		highestProductOf3 = max(highestProductOf3, max(highestProductOf2*currentNumber, lowestProductOf2*currentNumber));
		highestProductOf2 = max(highestProductOf2, max(currentNumber*highest, currentNumber*lowest));

		highest = max(highest, currentNumber);
		lowest = min(lowest, currentNumber);

		lowestProductOf2 = min(lowestProductOf2,min(currentNumber*highest, currentNumber*lowest));
		lowestProductOf3 = min(lowestProductOf3, min(lowestProductOf2*currentNumber, highestProductOf2*currentNumber));
	}

	return highestProductOf3;
}

int main()
{
	vector<int> nums = {-10,-10,1,3,2};

	cout << highestProductOf3(nums);


	return(0);
}