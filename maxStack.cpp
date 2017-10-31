#include <stack>
#include <vector> 
#include <iostream>

using namespace std;

class maxStack
{
private:
	stack<int> max_stack_;
	stack<int> maxes_stack_;

public:
	maxStack(): 
	max_stack_(),
	maxes_stack_()
	{}

	~maxStack()
	{}

	void push(int item)
	{
		max_stack_.push(item);
		if(maxes_stack_.empty() || maxes_stack_.top() < item)
		{
			maxes_stack_.push(item);
		}

		return;
	}

	void pop()
	{
		if(!max_stack_.empty())
		{
			if(max_stack_.top()==maxes_stack_.top())
			{
				maxes_stack_.pop();
			}
				max_stack_.pop();
		}
		else
			throw runtime_error("failed to pop from an empty stack");
	}

	int getMax() const
	{
		return maxes_stack_.top();
	}
};

int main(void)
{
	vector<int> nums = {1,2,3,4,5};
	maxStack stk;

	for(auto i: nums)
		stk.push(i);

	stk.pop();
	stk.pop();
	stk.pop();
	
	cout << stk.getMax();

	return(0);
}