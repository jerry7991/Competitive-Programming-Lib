#include <iostream>
#include <queue>
using namespace std;
template < typename T>
class TreeNode
{
public:
	TreeNode<T> *left;
	T data;
	TreeNode<T> *right;
	TreeNode(T data)
	{
		this->data=data;
	}
};
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
		//root data of left subtree
		cin>>data;
		if (data!=-1)
		{
			temp->left=new TreeNode<int>(data);
			input.push(temp->left);
		}else{
			temp->left=NULL;
		}
		//root data of right subtree
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
void printTree(TreeNode<int> *root)
{
	//base case
	if (!root)
	{
		return;
	}
	cout<<root->data<<" : ";
	if (root->left)
	{
		cout<<" L "<<root->left->data<<" , ";
	}
	if (root->right)
	{
		cout<<" R "<<root->right->data;
	}
	cout<<endl;
	printTree(root->left);
	printTree(root->right);
}
int height(TreeNode<int> *root)
{
	if (!root)
	{
		return 0;
	}
	int leftHeight=1+height(root->left);
	int rightHeight=1+height(root->right);
	return (leftHeight>rightHeight)?leftHeight :rightHeight;
}
int main()
{
	TreeNode<int> * root;
	root=takeInput();
	printTree(root);
	int h=height(root);
	cout<<"\n height of tree is"<<h<<endl;
}