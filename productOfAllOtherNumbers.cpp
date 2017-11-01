#include <vector> 
#include <iostream>

using namespace std; 

vector<int> productOfAllOtherNums(const vector<int> &nums)
{
	vector<int> left(nums.size());

	left[0] = 1;
	for(int i =1; i < nums.size(); i++)
	{
		left[i] = left[i-1]*nums[i-1];
	}

	int right = 1;
	for(int i = nums.size()-1; i>=0; i--)
	{
		left[i] = right*left[i];
		right *= nums[i];
	}

	return left;
}

int main()
{
	std::vector<int> nums = {1,2,3,4,5};
	vector<int> result = productOfAllOtherNums(nums);

	for(auto i: result)
		cout << i << " ";

	return(0);
}