#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode * takeInput()
{
	ListNode *head = nullptr, *temp = nullptr;
	int data = 0;
	while (data != -1)
	{
		cin >> data;
		if (data != -1) {
			if (head == nullptr)
			{
				head = new ListNode(data);
				temp = head;
			} else {
				temp->next = new ListNode(data);
				temp = temp->next;
			}
		}
	}
	return head;
}

void print(ListNode *head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
}