#include <iostream>
#include <queue>
using namespace std;
template <typename T> class BSTNode
{
public:
	BSTNode<T> *left;
	BSTNode<T> *right;
	T data;
	BSTNode(T data)
	{
		this->data=data;
	}
	BSTNode()
	{
		left=NULL;
		right=NULL;
	}
};
void takeInput(BSTNode<int>*root)
{
	queue<BSTNode<int>*> pending;
	int data;
	cin>>data;
	if (data==-1)
	{
		return;
	}
	root->data=data;
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
}
void print(BSTNode<int>*root)
{
	queue<BSTNode<int>*> pending;
	pending.push(root);
	pending.push(NULL);
	while(pending.size())
	{
		BSTNode<int>*temp=pending.front();
		pending.pop();
		if (!temp)
		{
			if(pending.size())
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
void find(BSTNode<int>*root , BSTNode<int>*ans ,int data)
{
	if (!root)
	{
		return;
	}
	if (root->data==data)
	{
		ans->data=data;
		return;
	}
	find(root->left , ans , data);
	find(root->right , ans , data);
}
int main()
{
	BSTNode<int>*root=new BSTNode<int>();
	takeInput(root);
	print(root);
	int data;
	cin>>data;
	BSTNode<int>*ans=new BSTNode<int>(-1);
	find(root , ans , data);
	if(ans->data!=-1)
	{
		cout<<ans->data<<endl;
	}
}