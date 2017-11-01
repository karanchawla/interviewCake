#include <iostream>
#include <vector> 

using namespace std;

class ListNode
{
public:
	int intValue_;
    ListNode* next_;

    ListNode(int value) :
        intValue_(value),
        next_(nullptr)
    {}

};

void deleteNode(ListNode* valueToBeDelted)
{
	ListNode* nextNode = valueToBeDelted->next_;

	if(nextNode)
	{
		valueToBeDelted->intValue_ = nextNode->intValue_;
		valueToBeDelted->next_ = nextNode->next_;
		delete valueToBeDelted;
	}
	else
		throw runtime_error("Can't delete the last node with this method");
}


int main()
{
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(3);

	a->next_ = b;
	b->next_ = c;

	deleteNode(a);

	return(0);
}

