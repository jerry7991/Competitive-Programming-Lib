#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T> class BinaryTreeNode
{
public:
	BinaryTreeNode<T>*left;
	BinaryTreeNode<T>*right;
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
	if (data==-1) return NULL;
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
bool isRange(int low,int high,int data)
{
	 return (low<=data && high>=data);
}
bool getAnswer(BinaryTreeNode<int>*root , int low ,int high , int &count)
{
	if(!root) return true;
	bool leftAns=getAnswer(root->left , low , high ,count);
	bool rightAns=getAnswer(root->right , low , high , count);
	if(leftAns && rightAns && isRange(low,high,root->data))
	{
		++count;
		return true;
	}
	return false;
}
int getCount(BinaryTreeNode<int>*root,int low,int high)
{
	int count=0;
	bool ans=getAnswer(root , low,high ,count);
	return count;
}
int main()
{
	BinaryTreeNode<int>*root=takeInput();
	while(1)
	{
		int low,high;
		cin>>low>>high;
		cout<<getCount(root,low,high)<<endl;
	}
}