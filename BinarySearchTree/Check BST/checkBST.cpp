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
};
class Answer
{
public:
	int minValue;
	int maxValue;
	bool isBst;
	Answer(int minValue , int maxValue , bool isBst)
	{
		this->minValue=minValue;
		this->maxValue=maxValue;
		this->isBst=isBst;
	}
};
BSTNode<int> * takeInput()
{
	int data;
	cin>>data;
	if (data==-1)	return NULL;
	//otherwise
	BSTNode<int> *root=new BSTNode<int>(data);
	queue<BSTNode<int>*> pending;
	pending.push(root);
	while(pending.size())
	{
		BSTNode<int> *temp=pending.front();
		pending.pop();
		//left subtree'r root node
		cin>>data;
		if (data!=-1)
		{
			temp->left=new BSTNode<int>(data);
			pending.push(temp->left);
		}else{
			temp->left=NULL;
		}
		//right subtree'r root node
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
Answer * checkBst(BSTNode<int> *root)
{
	if (!root)
	{
		Answer *ans=new Answer(INT_MAX , INT_MIN , true);
		return ans;
	}
	Answer * leftAns=checkBst(root->left);
	Answer * rightAns=checkBst(root->right);
	int minValue=min(root->data , min(leftAns->minValue , rightAns->minValue));
	int maxValue=max(root->data , max(leftAns->maxValue , rightAns->maxValue));
	bool is_bst=true;
	//there is total four condition
	if ((leftAns->maxValue)>(root->data))
	{
		is_bst=false;
	}
	if ((rightAns->minValue)<(root->data))
	{
		is_bst=false;
	}
	if (!(leftAns->isBst) || ! (rightAns->isBst))
	{
		is_bst=false;
	}
	Answer *ans=new Answer(minValue , maxValue , is_bst);
	return ans;
}
int main()
{
	BSTNode<int>*root=takeInput();
	Answer *ans=checkBst(root);
	if (ans->isBst)
	{
		cout<<"true";
	}else{
		cout<<"false";
	}
	cout<<endl;
	cout<<ans->minValue<<" "<<ans->maxValue;
}