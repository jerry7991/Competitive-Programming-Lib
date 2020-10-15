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
class Found
{
public:
	int value;
	bool isFoundK1;
	bool isFoundK2;
	Found()
	{
		value=-1;
		isFoundK1=false;
		isFoundK2=false;
	}
};
BSTNode<int>* takeInput()
{
	int data;
	cin>>data;
	if (data==-1) return NULL;
	BSTNode<int>*root=new BSTNode<int>(data);
	queue<BSTNode<int>*> pending;
	pending.push(root);
	while(pending.size())
	{
		BSTNode<int> *temp=pending.front();
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
void getAncestor(BSTNode<int> *root , int k1 , int k2 , Found *answer)
{
	if (!root)
	{
		return;
	}
	if ((root->data)>=k1 && (root->data)<k2)
	{
		if ((answer->value)==-1)
		{
			answer->value=root->data;
		}
	}
	if ((root->data)==k1)
	{
		answer->isFoundK1=true;
	}
	if ((root->data)==k2)
	{
		answer->isFoundK2=true;
	}
	if ((root->data)>k2)
	{
		getAncestor(root->left , k1 , k2, answer);
	}
	if ((root->data)<k1)
	{
		getAncestor(root->right , k1 , k2 , answer);
	}
	if ((root->data)>=k1 && (root->data)<k2)
	{
		getAncestor(root->left , k1 , k2 , answer);
		getAncestor(root->right,k1,k2,answer);
	}
}
int main()
{
	BSTNode<int>*root=takeInput();
	Found *answer=new Found();
	int k1,k2;
	cin>>k1>>k2;
	getAncestor(root ,k1,k2 ,answer);
	if (answer->isFoundK1 && answer->isFoundK2)
	{
		cout<<answer->value;
	}else{
		cout<<-1;
	}
}