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
void printPreOrder(TreeNode<int>*root)
{
	if (!root)
	{
		return;
	}
	cout<<root->data<<" ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}
int main()
{
	TreeNode<int> *root=takeIntput();
	printPreOrder(root);
}