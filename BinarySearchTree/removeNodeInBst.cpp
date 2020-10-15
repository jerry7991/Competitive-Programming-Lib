#include <iostream>
#include <queue>
using namespace std;
template <typename T> class BSTNode
{
public:
	BSTNode<T>*left;
	BSTNode<T>*right;
	T data;
	BSTNode(T data)
	{
		this->data=data;
	}
	
};
BSTNode<int> * takeInput()
{
	int data;
	cin>>data;
	if (data==-1) return NULL;
	BSTNode<int>*root=new BSTNode<int>(data);
	queue<BSTNode<int>*> pending;
	pending.push(root);
	while(pending.size())
	{
		BSTNode<int>*temp=pending.front();
		pending.pop();
		cin>>data;
		if (data!=-1)
		{
			temp->left=new BSTNode<int>(data);
			pending.push(temp->left);
		}else{
			temp->left=NULL;
		}
		cin>>data;
		if (data!=-1)
		{
			temp->right=new BSTNode<int>(data);
			pending.push(temp->right);
		}else{
			temp->right=NULL;
		}
	}
	return root;
}
void print(BSTNode<int>* root){
	queue<BSTNode<int>*>pending;
	pending.push(root);
	pending.push(NULL);
	while(pending.size())
	{
		BSTNode<int>*temp=pending.front();
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
BSTNode<int>* deleteNode(BSTNode<int>*root , int data)
{
	if (!root)
	{
		return NULL;
	}
	if ((root->data)<data)
	{
		root->right=deleteNode(root->right , data);
	}
	if((root->data)>data)
	{
		root->left=deleteNode(root->left,data);
	}
	if ((root->data)==data)
	{
		//there would be three case
		//case 1: subtree has no child
		if(!root->left && !root->right)
		{
			//just return null
			return NULL;
		}else if (root->left && !root->right)
		{
			//only left child
			return root->left;
		}else if(!root->left && root->right)
		{
			//only right child
			return root->right;
		}
			//has left and right child so find min from right and put into current root->data
			//and set data to be deleted to currMin cause now it has 1 more time
			BSTNode<int>*temp=root->right;
			while(temp->left)
			{
				temp=temp->left;
			}
			root->data=temp->data;
			data=temp->data;
			root->right=deleteNode(root->right,data);
	}
	return root;
}
int main()
{
	BSTNode<int>*root=takeInput();
	int data;
	cin>>data;
	print(root);
	root=deleteNode(root,data);
	cout<<"\n after delete the given node tree is :\n";
	print(root);
}