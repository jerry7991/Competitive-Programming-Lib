#include <iostream>
using namespace std;
template <typename T> class LNode
{
public:
	LNode<T>*next;
	T data;
	LNode(T data)
	{
		this->data=data;
		next=NULL;
	}
};
template <typename T> class BinaryTreeNode
{
public:
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;
	T data;
	BinaryTreeNode(T data)
	{
		this->data=data;
	}
};
BinaryTreeNode<int> *build(LNode<int> * head , int start , int end)
{
	if (start>end)
	{
		return NULL;
	}
	cout<<start<<" "<<end<<endl;
	int mid=(start+end)/2;
	int rootData;
	LNode<int>*temp=head;
	int x=mid;
	while(x)
	{
		x--;
		temp=temp->next;
	}
	rootData=temp->data;
	BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
	root->left=build(head , start , mid-1);
	root->right=build(head , mid+1 , end);
	return root;
}
BinaryTreeNode<int> * sortedListToBST(LNode<int>* head)
{
	LNode<int>*temp=head;
	int size=0;
	while(temp)
	{
		size++;
		temp=temp->next;
	}
	return build(head , 0 ,size-1);
}
void print(BinaryTreeNode<int>*root)
{
	if(!root)return;
	print(root->left);
	cout<<root->data<<" ";
	print(root->right);
}
int main()
{
	int data;
	cin>>data;
	LNode<int> *head=new LNode<int>(data);
	LNode<int>*temp=head;
	while(1)
	{
		cin>>data;
		if(data==-1) break;
		temp->next=new LNode<int>(data);
		temp=temp->next;
	}
	BinaryTreeNode<int>*root=sortedListToBST(head);
	print(root);
}