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
TreeNode<int> * takeInput()
{
	queue<TreeNode<int>*> input;
	int data;
	cin>>data;
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
void printTree(TreeNode<int>*root)
{
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
bool checkPresent(TreeNode<int>* root  ,int data)
{
	if (!root)
	{
		return false;
	}
	if (root->data==data)
	{
		return true;
	}
	return (checkPresent(root->left  , data) || checkPresent(root->right  , data));
}
int main()
{
	TreeNode<int>*root;
	root=takeInput();
	printTree(root);
	int data;
	cin>>data;
	bool isPresent=checkPresent(root  , data);
	if (isPresent)
	{
		cout<<"true";
	}else{
		cout<<"false";
	}
}