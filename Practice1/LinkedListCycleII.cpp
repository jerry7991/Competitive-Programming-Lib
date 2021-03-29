#include<iostream>
#include "LinkedList.h"
using namespace std;
ListNode *detectCycle(ListNode *head) {
	ListNode *fast = head;
	ListNode *slow = head;
	ListNode *ptr1 = head;
	ListNode *ptr2 = head;
	bool isCycle = false;

	while(!isCycle && fast && fast->next)
	{
		slow = slow ->next;
		fast = fast->next->next;
		if(slow == fast)
		{
			isCycle = true;
			ptr2 = slow;
		}
	}

	while(ptr1 && ptr2->next && ptr1!=ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return isCycle?ptr1:nullptr;
}

int main() {
	ListNode *head = takeInput();
	print(head);

	head = detectCycle(head);
	cout << head->data << endl;

	return 0;
}
