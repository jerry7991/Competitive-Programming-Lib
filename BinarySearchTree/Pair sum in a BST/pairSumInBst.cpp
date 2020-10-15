#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename T> class BSTNode
{
public:
	BSTNode<int> *left;
	BSTNode<int> *right;
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
	if (data==-1)
	{
		return NULL;
	}
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
void printSumToK(BSTNode<int> *root  , vector<int>& output)
{
	if (!root)
	{
		return;
	}
	printSumToK(root->left , output);
	output.push_back(root->data);
	printSumToK(root->right , output);
}
int main()
{
	BSTNode<int> *root=takeInput();
	int k;
	cin>>k;
	std::vector<int> v;
	printSumToK(root ,v);
	int start=0,end=v.size()-1;
	while((start<end)  && v[start]<=k)
	{
		if (v[end]>(k-v[start]))	end--;
		else if (v[end]==(k-v[start]))
		{
			cout<<v[start]<<" "<<v[end]<<endl;
			start++;
		}
		else if (v[end]<(k-v[start])) start++;
	}
}