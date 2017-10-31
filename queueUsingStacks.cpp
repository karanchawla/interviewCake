#include <stack>
#include <iostream>
#include <vector> 

using namespace std; 

class Queue
{
private:
	stack<int> inStack;
	stack<int> outStack;

public:
	void enQueue(int item)
	{
		inStack.push(item);
	}

	int deQueue()
	{
		
		if(outStack.empty())
		{
			while(!inStack.empty())
			{
				int topItem = inStack.top();
				inStack.pop();
				outStack.push(topItem);
			}
		}

		if(outStack.empty())
		{
			throw runtime_error("Failed to dequeue from an empty quque");
		}

		int result = outStack.top();	
		outStack.pop();
		return result;
	}

};

int main()
{
	Queue q;
	vector<int> nums = {1};
	for(auto i: nums)
	{
		q.enQueue(i);
	}

	cout << q.deQueue();
	cout << q.deQueue();

	return(0);
}