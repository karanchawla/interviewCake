#include <iostream>

using namespace std; 

class LinkedListNode
{
public:
    int value_;
    LinkedListNode* next_;

    LinkedListNode(int value) :
        value_(value),
        next_(nullptr)
    {
    }
};

bool containsCycle(LinkedListNode* firstNode)
{
	LinkedListNode* slowRunner = firstNode;
	LinkedListNode* fastRunner = firstNode;

	while(fastRunner!=nullptr && slowRunner!=nullptr)
	{
		slowRunner = slowRunner->next_;
		fastRunner = fastRunner->next_->next_;

		if(slowRunner==fastRunner)
			return true;
	}

	return false;
}

