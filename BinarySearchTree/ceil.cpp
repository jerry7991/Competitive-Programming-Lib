//https://codezen.codingninjas.com/practice/524/2253/floor-from-bst
#include <bits/stdc++.h>
using namespace std;
template <typename T> class BSTNode
{
public:
	BSTNode<T> *left;
	BSTNode<T> *right;
	T data;
	BSTNode(T data)
	{
		this->data=data;
	}
};
BSTNode<int>* takeInput()
{
	int data;
	cin>>data;
	if(data==-1) return NULL;
	BSTNode<int>*root=new BSTNode<int>(data);
	queue<BSTNode<int>*>pending;
	pending.push(root);
	while(pending.size())
	{
		BSTNode<int>*temp=pending.front();
		pending.pop();
		cin>>data;
		if(data!=-1)
		{
			temp->left=new BSTNode<int>(data);
			pending.push(temp->left);
		}else{
			temp->left=NULL;
		}
		cin>>data;
		if(data!=-1)
		{
			temp->right=new BSTNode<int>(data);
			pending.push(temp->right);
		}else{
			temp->right=NULL;
		}
	}
	return root;
}
void getCeil(BSTNode<int>*root , int key , int & flor)
{
	if(!root)	 return ;
	if((root->data)<=key)
	{
		getCeil(root->right , key , flor);
	}else
	{
		flor=root->data;
		getCeil(root->left , key , flor);
	}
}
int main()
{
	BSTNode<int>*root=takeInput();
	int flor=INT_MAX;
	while(1)
	{
	int key;
	cin>>key;
	if(key==0)	return 0;
	getCeil(root,key,flor);
	cout<<flor<<endl;
	}
	return 0;
}
/*
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
*/