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
int getSum(TreeNode<int>*root)
{
	if (!root)
	{
		return 0;
	}
	int data=root->data;
	int leftSum=getSum(root->left);
	int rightSum=getSum(root->right);
	return (data+leftSum+rightSum);
}
int main()
{
	TreeNode<int> *root=takeIntput();
	getSum(root);
	cout<<getSum(root);
}