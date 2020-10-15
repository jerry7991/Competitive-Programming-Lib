#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename T> class BinaryTreeNode
{
public:
	BinaryTreeNode<int> *left;
	BinaryTreeNode<int> *right;
	T data;
	BinaryTreeNode(T data)
	{
		this->data=data;
	}
};
BinaryTreeNode<int> * takeInput()
{
	int data;
	cin>>data;
	if (data==-1)
	{
		return NULL;
	}
	BinaryTreeNode<int>*root=new BinaryTreeNode<int>(data);
	queue<BinaryTreeNode<int>*> pending;
	pending.push(root);
	while(pending.size())
	{
		BinaryTreeNode<int>*temp=pending.front();
		pending.pop();
		cin>>data;
		if (data!=-1)
		{
			temp->left=new BinaryTreeNode<int>(data);
			pending.push(temp->left);
		}else{
			temp->left=NULL;
		}
		cin>>data;
		if (data!=-1)
		{
			temp->right=new BinaryTreeNode<int>(data);
			pending.push(temp->right);
		}else{
			temp->right=NULL;
		}
	}
	return root;
}
void setMax(BinaryTreeNode<int>*root ,int x, int &k)
{
	if (!root)
	{
		return;
	}
	k=max(k,root->data);
	if (root->data==x)
	{
		return;
	}
	if ((root->data)<x)
	{
		setMax(root->right,x,k);
	}
	else if((root->data)>x)
	{
		setMax(root->left ,x,k);
	}
}
void find(BinaryTreeNode<int>*root , int k1,int k2,int& k)
{
	if (!root)
	{
		return;
	}
	if ((root->data)<=k2 && (root->data)>=k1)
	{
		setMax(root ,k2, k);
		return;
	}
	else if((root->data)>k2)
	{
		find(root->left , k1,k2,k);
	}else if((root->data)<k1)
	{
		find(root->right , k1,k2,k);
	}

}
int main()
{
	BinaryTreeNode<int> *root=takeInput();
	int k1,k2;
	cin>>k1>>k2;
	if(k1>k2)
	{
		int p=k2;
		k2=k1;
		k1=p;
	}
	int k=-1;
	find(root,k1,k2,k);
	cout<<k;
}