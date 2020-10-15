#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void print(ListNode *list){
	if(!list) return ;
	cout<<list->val<<' ';
	print(list->next);
}
void reorderList(ListNode* head) {
	if(!head->next) return;
	stack<ListNode *> st;
	int count=1;
	ListNode *temp=head;
	while(temp){
		count++;
		st.push(temp);
		temp=temp->next;
	}
	temp=head;
	while(count>=0){
		ListNode * next=temp->next;
		temp->next=st.top();
		temp=temp->next;
		temp->next=next;
		st.pop();
		temp=temp->next;
		count-=3;
	}
	if(temp) temp=temp->next;
	temp->next=nullptr;
}
int main(){
	int x;
	cin>>x;
	ListNode * list=new ListNode(x);
	ListNode *temp=list;
	while(true){
		cin>>x;
		if(x==0) break;
		temp->next=new ListNode(x);
		temp=temp->next;
	}
	print(list);
	reorderList(list);
	cout<<'\n';
	print(list);
	return 0;
}
/*
https://leetcode.com/explore/featured/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3430/discuss/802629/easy-way-with-stack
*/