#include <iostream>
#include <queue>
using namespace std;
template <typename T> class TreeNode
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
queue<TreeNode<int>*> pending;
TreeNode<int> * takeInput()
{
	int rootData;
	cin>>rootData;
	if (rootData==-1)
	{
		return NULL;
	}
	TreeNode<int>*root=new TreeNode<int>(rootData);
	pending.push(root);
	while(pending.size())
	{
		TreeNode<int>*temp=pending.front();
		pending.pop();
		//left child
		cin>>rootData;
		if (rootData!=-1)
		{
			temp->left=new TreeNode<int>(rootData);
			pending.push(temp->left);
		}else{
			temp->left=NULL;
		}
		//right child
		cin>>rootData;
		if (rootData!=-1)
		{
			temp->right=new TreeNode<int>(rootData);
			pending.push(temp->right);
		}else{
			temp->right=NULL;
		}
	}
	return root;
}
void modify(TreeNode<int>*root)
{
	if (!root)
	{
		return;
	}
	TreeNode<int >*duplicate=new TreeNode<int>(root->data);
	duplicate->left=root->left;
	duplicate->right=NULL;
	root->left=duplicate;
	modify(root->left->left);
	modify(root->right);
}
void print(TreeNode<int>* root)
{
	pending.push(root);
	pending.push(NULL);
	while(pending.size())
	{
		TreeNode<int>*temp=pending.front();
		pending.pop();
		if (!temp)
		{
			if (pending.size())
			{
				pending.push(NULL);
				cout<<endl;
			}
		}else{
			cout<<temp->data<<" ";
			if (temp->left)
			{
				pending.push(temp->left);
			}
			if (temp->right)
			{
				pending.push(temp->right);
			}
		}
	}
}
int main()
{
	TreeNode<int>*root=takeInput();
	print(root);
	modify(root);
	cout<<"\n modified Tree is "<<endl;
	print(root);
	return 0;
}