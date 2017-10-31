#include <vector>
#include <iostream>

using namespace std;

int findStolenDrone(const vector<int> &DeliverIds)
{
	int stolenDroneID = DeliverIds[0];
	for(int order = 1; order < DeliverIds.size(); order++)
	{
		stolenDroneID ^= DeliverIds[order];
	}

	return stolenDroneID;
}

int main()
{
	vector<int> nums = {1, 2, 3, 4, 5, 1, 2, 3, 5};
	cout << findStolenDrone(nums);

}