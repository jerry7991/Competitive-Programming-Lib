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
void inorder(BSTNode<int>*root,vector<int>& inOrder)
{
	if(!root) return;
	inorder(root->left,inOrder);
	inOrder.push_back(root->data);
	inorder(root->right , inOrder);
}
bool isSame(BSTNode<int>* root1 ,BSTNode<int>*root2)
{
	vector<int> inOrder1;
	vector<int> inOrder2;
	inorder(root1,inOrder1);
	inorder(root2,inOrder2);
	if(inOrder1.size()!=inOrder2.size())	return false;
	//cout<<inOrder1.size()<<" "<<inOrder2.size()<<endl;
	for (unsigned int i = 0; i < inOrder1.size(); ++i)
	{
		//cout<<inOrder1[i]<<" "<<inOrder2[i]<<endl;
		if (inOrder1[i]!=inOrder2[i]) return false;
	}
	return true;
}
int main()
{
	BSTNode<int>*root1=takeInput();
	BSTNode<int>*root2=takeInput();
	cout<<isSame(root1,root2);
}
/*
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
*/