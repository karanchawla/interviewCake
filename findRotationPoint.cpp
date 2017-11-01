#include <iostream>
#include <vector>
#include <string>

using namespace std; 

size_t findRotationPoint(const vector<string>& words)
{
	size_t floorIndex = 0;
	size_t ceilingIndex = words.size() - 1;

	while(floorIndex < ceilingIndex)
	{
		size_t guessIndex = floorIndex + (ceilingIndex - floorIndex)/2;

		if(words[guessIndex] >= words[0])
			floorIndex = guessIndex;

		else
			ceilingIndex = guessIndex;

		if(floorIndex+1 == ceilingIndex)
			break;
	}

	return ceilingIndex;
}