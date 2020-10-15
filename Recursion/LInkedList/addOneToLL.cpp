#include <iostream>
using namespace std;
template <typename T> class Node
{
public:
	Node<T>*next;
	T data;
	Node(T data)
	{
		this->data=data;
		next=NULL;
	}
};
int getRemainder(Node<int>*head)
{
	if(!head)
		return 1;
	int x=getRemainder(head->next);
	int sum=head->data+x;
	head->data=sum%10;
	return sum/10;
}
Node<int>* addOne(Node<int> *head) 
{   

	int x=getRemainder(head);
	if(x!=0)
	{
		Node<int>*temp=new Node<int>(x);
		temp->next=head;
		head=temp;
	}
	return head;
}
int main()
{
	int data;
	cin>>data;
	Node<int> *head=new Node<int>(data);
	Node<int>*temp=head;
	while(1)
	{
		cin>>data;
		if(data==-1) break;
		temp->next=new Node<int>(data);
		temp=temp->next;
	}
	temp=addOne(head);
	while(temp)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}