//https://codezen.codingninjas.com/practice/524/2287/pair-with-given-sum-in-a-balanced-bst
#include <iostream>
#include <queue>
#include <vector>
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
BSTNode<int>* takeInput()
{
	int data;
	cin>>data;
	if(data==-1) return NULL;
	BSTNode<int>*root=new BSTNode<int>(data);
	queue<BSTNode<int>*>pending;
	pending.push(root);
	while(pending.size())
	{
		BSTNode<int>*temp=pending.front();
		pending.pop();
		cin>>data;
		if(data!=-1)
		{
			temp->left=new BSTNode<int>(data);
			pending.push(temp->left);
		}else{
			temp->left=NULL;
		}
		cin>>data;
		if(data!=-1)
		{
			temp->right=new BSTNode<int>(data);
			pending.push(temp->right);
		}else{
			temp->right=NULL;
		}
	}
	return root;
}
void getInorder(BSTNode<int> *root,vector<int>& inOrder)
{
	if(!root) return;
	getInorder(root->left , inOrder);
	inOrder.push_back(root->data);
	getInorder(root->right , inOrder);
}
bool isPairPresent(BSTNode<int> *root,int sum)
{
	vector<int> inOrder;
	getInorder(root,inOrder);
	int n=inOrder.size();
	int i=0;
	while(i<n)
	{
		if((sum-inOrder[i])>inOrder[n-1])	i++;
		else if((sum-inOrder[i])<inOrder[n-1])	n--;
		else if((sum-inOrder[i])==inOrder[n-1]) return true;
	}
	return false;
}
int main()
{
	BSTNode<int> *root=takeInput();
	int sum;
	cin>>sum;
	bool ans=isPairPresent(root,sum);
	if(ans) cout<<"true";
	else cout<<"false";
	return 0;
}