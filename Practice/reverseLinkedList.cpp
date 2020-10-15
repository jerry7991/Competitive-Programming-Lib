#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int data): val(data),next(nullptr){}
};
ListNode *takeInput(){
	ListNode *head=nullptr,*tail=nullptr;
	int val;cin>>val;
	if(val==-1){
		return nullptr;
	}
	while(val!=-1){
		if(head==nullptr && tail==nullptr){
			head=new ListNode(val);
			tail=head;
		}else{
			tail->next=new ListNode(val);
			tail=tail->next;
		}
		cin>>val;
	}
	return head;
}
void print(ListNode *head){
	while(head!=nullptr){
		cout<<head->val<<' ';
		head=head->next;
	}
}
//	O(N*N) time , O(N) space
ListNode* reverseList(ListNode* head) {
    if(head==nullptr || head->next==nullptr){
    	return head;
    }
    ListNode *newHead=reverseList(head->next);
    ListNode *tail=newHead;
    while(tail->next!=nullptr){
    	tail=tail->next;
    }
    tail->next=head;
    head->next=nullptr;
    return newHead;
}

struct Node{
	ListNode *tail,*head;
	Node(): tail(nullptr),head(nullptr){}
};
//	O(N) time , O(N) space
Node *reverseListIIHelper(ListNode *head){
	if(head==nullptr || head->next==nullptr){
		Node *newNode=new Node();
		newNode->head=newNode->tail=head;
		return newNode;
	}
	Node *newNode=reverseListIIHelper(head->next);
	newNode->tail->next=head;
	newNode->tail=head;
	head->next=nullptr;
	return newNode;
}

ListNode* reverseListII(ListNode *head){
	Node *newNode=reverseListIIHelper(head);
	return newNode->head;
}

//	O(N) time , O(1) space
ListNode *reverseListIII(ListNode *head){
	ListNode *prev=nullptr , *nextNode=nullptr;
	while(head!=nullptr){
		//	hold the next node
		nextNode=head->next;

		//	point back
		head->next=prev;

		// 	move forward
		prev=head;

		//	 go for next node
		head=nextNode;
	}
	return prev;
}
int main(){
	ListNode *head=takeInput();
	print(head);
	cout<<'\n';
	head=reverseListIII(head);
	print(head);
	return 0;
}