#include <iostream> 

using namespace std;

 class LinkedListNode
{
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int intValue) :
        intValue_(intValue),
        next_(nullptr)
    {
    }
};

LinkedListNode* reverseLinkedList(LinkedListNode* head)
{
	LinkedListNode* current = head;
	LinkedListNode* prev = nullptr;
	LinkedListNode* next = nullptr;

	while(current)
	{
		next = current->next_;
		
		current->next_ = prev;


		prev = current;
		current = next;
	}

	return prev;
}