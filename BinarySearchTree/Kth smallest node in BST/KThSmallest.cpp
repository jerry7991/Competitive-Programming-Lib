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
void findNode(BinaryTreeNode<int>* root,  vector<int> &v) {
	if (!root)		return ;
	findNode(root->left);
	v.push_back(root->data);
	findNode(root->right);
}
int main()
{
	BinaryTreeNode<int> *root=takeInput();
	int k;
	cin>>k;
	vector<int> v;
	findNode(root,v);
	if (k>=v.size())
	{
		cout<<INT_MIN;
	}else{
		cout<<v[k-1];
	}
}