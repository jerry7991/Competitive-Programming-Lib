/*
	https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3386/
*/
#include <iostream>
using namespace std;
class Node{
public:
	int val;
	Node *prev;
	Node *next;
	Node *child;
};
int main(){
	if(head==NULL) return NULL;
	Node *temp;
	Node *tail=head;
	while(tail->next){
		tail=tail->next;
	}
	Node *curr=head;
	while(curr!=tail){
		if(curr->child){
			tail->next=curr->child;
			while(temp->next){
				temp=temp->next;
			}
			tail=temp;
		}
		curr=curr->next;
	}
	return head;
}