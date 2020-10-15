#include <iostream>
#include <queue>
using namespace std;
int nSibling=0;
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
TreeNode<int> * takeInput()
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
		TreeNode<int>*temp=input.front();
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
void findNSibling(TreeNode<int> *root)
{
	if (!root)
	{
		return;
	}
	if (root->left==NULL && root->right!=NULL)
	{
		cout<<root->right->data<<endl;
	}else if(root->left!=NULL && root->right==NULL)
	{
		cout<<root->left->data<<endl;
	}
	findNSibling(root->left);
	findNSibling(root->right);
}
int main()
{
	TreeNode<int>  *root=takeInput();
	findNSibling(root);
}
