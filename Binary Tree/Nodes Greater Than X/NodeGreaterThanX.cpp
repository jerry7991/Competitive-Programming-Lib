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
int count=0;
TreeNode<int> * takeInput()
{
	queue<TreeNode<int>*> input;
	int data;
	cin>>data;
	if (data==-1)
	{
		return NULL;
	}
	TreeNode<int> *root=new TreeNode<int>(data);
	input.push(root);
	while(!input.empty())
	{
		TreeNode<int> *temp=input.front();
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
void findGreaterToX(TreeNode<int> *root , int X)
{
	if (!root)
	{
		return ;
	}
	if (root->data>X)
	{
		count++;
	}
	findGreaterToX(root->left,X);
	findGreaterToX(root->right,X);
}
int main()
{
	TreeNode<int> *root=takeInput();
	int X;
	cin>>X;
	findGreaterToX(root , X);
	cout<<count;
}