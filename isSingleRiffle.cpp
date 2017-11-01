#include <vector> 
#include <iostream>

using namespace std;

bool isRiffle(
	const vector<int> &half1,
	const vector<int> &half2,
	const vector<int> &deck
	)
{
	size_t half1Index = 0;
	size_t half2Index = 0;
	size_t deckIndex = 0;
	size_t half1MaxIndex = half1.size() - 1;
	size_t half2MaxIndex = half2.size() - 1;

	for(int currDeckIndex = 0; currDeckIndex < deck.size()-1; currDeckIndex++)
	{
		if(half1[half1Index]==deck[deckIndex] && half1Index <= half1MaxIndex)
			half1Index++;

		else if(half2[half2Index]==deck[deckIndex] && half2Index <= half2MaxIndex)
			half2Index++:

		else 
			return false;

	}	
	
	return true;

}