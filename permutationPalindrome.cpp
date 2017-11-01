#include <iostream>
#include <string> 
#include <unordered_set>

using namespace std;

bool isPermutationPalindrome(const string& inputString)
{
	unordered_set<char> unPairedChars; 

	for(auto c: inputString)
	{
		if(unPairedChars.find(c)!=unPairedChars.end())
			unPairedChars.erase(c);
		else
			unPairedChars.insert(c);
	} 

	return unPairedChars.size() <=1;
}

int main()
{

	string str = "icvic";

	cout << isPermutationPalindrome(str);

	return(0);
}
