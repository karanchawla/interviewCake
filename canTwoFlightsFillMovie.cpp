#include <vector> 
#include <unordered_set>
#include <set>

using namespace std;

bool canTwoMoviesFillFlight(vector<int> movieTimes, int flightTime)
{
	unordered_set<int> movieLenghtsSeen;

	for(int i = 0; i < movieTimes.size(); i++)
	{
		int matchingSecondMovieLength = flightTime - movieTimes[i];
		if(movieLenghtsSeen.find(matchingSecondMovieLength)!=movieLenghtsSeen.end())
		{
			return true;
		}

		movieLenghtsSeen.insert(movieTimes[i]);
	}

	return false;
}