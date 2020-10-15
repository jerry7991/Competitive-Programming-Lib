#include <iostream>
#include <queue>
#include <stack>
#define bst BinaryTreeNode
using namespace std;
template <typename T> class bst
{
public:
	bst<T>*left;
	bst<T>*right;
	T data;
	bst(T data)
	{
		this->data=data;
	}
};
bst<int> * takeInput()
{
	int data;
	cin>>data;
	if(data==-1)return NULL;
	bst<int>*root=new bst<int>(data);
	queue<bst<int>*> pending;
	pending.push(root);
	while(pending.size())
	{
		bst<int>*temp=pending.front();
		pending.pop();
		cin>>data;
		if(data!=-1)
		{
			temp->left=new bst<int>(data);
			pending.push(temp->left);
		}else{
			temp->left=NULL;
		}
		cin>>data;
		if(data!=-1)
		{
			temp->right=new bst<int>(data);
			pending.push(temp->right);
		}else{
			temp->right=NULL;
		}
	}
	return root;
}
void print(bst<int>*root)
{
	queue<bst<int>*> q;
	q.push(root);
	q.push(NULL);
	while(q.size())
	{
		bst<int>*temp=q.front();
		q.pop();
		if(!temp)
		{
			if(q.size())
			{
				q.push(NULL);
				cout<<endl;
			}
		}else{
			cout<<temp->data<<" ";
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
}
void swap(int *a , int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void helper(bst<int>*root , bst<int> **first , bst<int>**mid , bst<int>**last , bst<int>**prev)
{
	if(!root )	return;
	helper(root->left , first , mid , last , prev);
	//now returning we know this is inorder i.e. incresing order
	//if current node is smaller than the prev node then this first fault
	if (*prev && (root->data)<(*prev)->data)
	{
		//check weather this is first voilation
		if (!(*first))
		{
			//if it was null then it is first voilation... store the address of current node
			*first=*prev;
			*mid=root;
		}else{
			//this is the second voilation
			*last=root;
		}
	}
	//mark current node as prev
	*prev=root;
	//recurs for the right subtree as well
	helper(root->right , first , mid , last , prev);
}
bst<int>* correctBSt(bst<int>*root)
{
	bst<int>* first,*mid,*last,*prev;
	first=mid=last=prev=NULL;
	helper(root , &first , &mid , &last , &prev);
	//let's the fix tree
	if (prev && last)
	{
	swap(&(first->data) , &(last->data));
	}else{
		swap(&(first->data) , &(mid->data));
	}
	return root;
}
int main()
{
	bst<int>*root=takeInput();
	print(root);
	root=correctBSt(root);
	cout<<endl;
	print(root);
}