#include <iostream>
#include <string>

using namespace std;

size_t getClosingParanthesis(const string& inputString, size_t openingParanIndex)
{
	size_t nestedParanIndex = 0;
	for (int i = openingParanIndex + 1; i < inputString.size(); ++i)
	{
		if(inputString[i]=='(')
			++nestedParanIndex;

		else if(inputString[i] == ')')
		{
			if(nestedParanIndex==0)
				return i;
			else
				--nestedParanIndex;
		}
	}

	throw runtime_error("no closing parenthesis found");
}


int main()
{

	string inputString = "((((()))))";
	cout << getClosingParanthesis(inputString, 1);

}