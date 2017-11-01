#include <iostream>
#include <vector> 

using namespace std; 

nt getMaxProfit(const vector<int> &prices)
{
	if(prices.size() < 2)
		throw invalid_argument("Prices size should be atleast two");

	int minPrice = prices[0];
	int maxProfit = prices[1] - prices[0];

	for(int i = 1; i < prices.size(); i++)
	{
		int potentialProfit = prices[i] - minPrice;

		maxProfit = max(maxProfit, potentialProfit);

		minPrice = min(prices[i], minPrice);
	}

	return maxProfit;
}