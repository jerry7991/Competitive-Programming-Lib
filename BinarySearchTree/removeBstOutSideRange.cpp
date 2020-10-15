#include <iostream>
#include <queue>
using namespace std;
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
BinaryTreeNode<int>* takeInput()
{
	int data;
	cin>>data;
	if(data==-1)return NULL;
	BinaryTreeNode<int> * root=new BinaryTreeNode<int>(data);
	queue<BinaryTreeNode<int>*>pending;
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
void print(BinaryTreeNode<int>*root)
{
	queue<BinaryTreeNode<int>*> pending;
	pending.push(root);
	pending.push(NULL);
	while(pending.size())
	{
		BinaryTreeNode<int> *temp=pending.front();
		pending.pop();
		if(!temp)
		{
			if(pending.size())
			{
				pending.push(NULL);
				cout<<endl;
			}
		}else{
			cout<<temp->data<<" ";
			if(temp->left) pending.push(temp->left);
			if(temp->right)	pending.push(temp->right);
		}
	}
}
BinaryTreeNode<int>* removeOutsideRange(BinaryTreeNode<int> *root, int min, int max)
{
	if(!root) return NULL;
	root->left=removeOutsideRange(root->left ,  min , max);
	root->right=removeOutsideRange(root->right , min ,max);
	//check weather the current root-data 
	if ((root->data)<min)
	{
		BinaryTreeNode<int>*node=root->right;
		delete root;
		return node;
	}
	if((root->data)>max)
	{
		BinaryTreeNode<int>*node=root->left;
		delete root;
		return node;
	}
	return root;
}
int main()
{
	BinaryTreeNode<int> *root=takeInput();
	int low,high;
	cin>>low>>high;
	print(root);
	cout<<"\n after deletion \n";
	root=removeOutsideRange(root , low , high);
	print(root);
}