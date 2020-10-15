#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class TreeNode
{
public:
	TreeNode<T> *left;
	TreeNode<T> *right;
	T data;
	TreeNode(T data)
	{
		this->data=data;
	}
};
TreeNode<int> * takeIntput()
{
	int data;
	cin>>data;
	if (data==-1)
	{
		return NULL;
	}
	queue<TreeNode<int>*> input;
	TreeNode<int> *root=new TreeNode<int>(data);
	input.push(root);
	while(!input.empty())
	{
		TreeNode<int> * temp=input.front();
		input.pop();
		cin>>data;
		if (data!=-1)
		{
			temp->left=new TreeNode<int>(data);
			input.push(temp->left);
		}else{
			temp->left=NULL;
		}
		cin>>data;
		if (data!=-1)
		{
			temp->right=new TreeNode<int>(data);
			input.push(temp->right);
		}else{
			temp->right=NULL;
		}
	}
	return root;
}
void replaceNode(TreeNode<int> *root)
{
	if (!root)
	{
		return;
	}
	if (root->left)
	{
		root->left->data=root->data+1;
	}
	if (root->right)
	{
		root->right->data=root->data+1;
	}
	replaceNode(root->left);
	replaceNode(root->right);
}
void printInorder(TreeNode<int> *root)
{
	if (!root)
	{
		return;
	}
	printInorder(root->left);
	printf("%d\n",root->data);
	printInorder(root->right);
}
int main()
{
	TreeNode<int> *root=takeIntput();
	root->data=0;
	replaceNode(root);
	printInorder(root);
}