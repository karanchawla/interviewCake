#include <vector> 
#include <iostream> 

using namespace std;

vector<int> sortScores(const vector<int>& scores, int highestPossibleScore) 
{
	vector<int> sortedScores(scores.size());
	vector<int> frequencyOfScores(highestPossibleScore + 1);

	for(auto i: scores)
		frequencyOfScores[i]++;
	
	for(auto i : frequencyOfScores)
		cout << i << " ";
	cout << endl;

	int sortedIndex = 0;

	for(int i = highestPossibleScore; i>=0; i--)
	{
		size_t count = frequencyOfScores[i];
		
		for(int j = 0; j < count; j++)
		{
			sortedScores[sortedIndex++] = i;
		}
	}

	return sortedScores;
}

int main()
{
	vector<int> scores = {1, 2, 1, 3, 4, 100, 10, 10, 80, 80};

	vector<int> result = sortScores(scores, 100);
	for(auto i: result)
		cout << i << " ";

	return(0);
}