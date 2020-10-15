#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
template <typename T> class BinaryTreeNode
{
public:
	BinaryTreeNode<T>*left;
	BinaryTreeNode<T>*right;
	T data;
	BinaryTreeNode(T data)
	{
		this->data=data;
	}
	
};
BinaryTreeNode<int> * takeInput()
{
	int data;
	cin>>data;
	if (data==-1) return NULL;
	BinaryTreeNode<int>*root=new BinaryTreeNode<int>(data);
	queue<BinaryTreeNode<int>*> pending;
	pending.push(root);
	while(pending.size())
	{
		BinaryTreeNode<int>*temp=pending.front();
		pending.pop();
		cin>>data;
		if (data!=-1)
		{
			temp->left=new BinaryTreeNode<int>(data);
			pending.push(temp->left);
		}else{
			temp->left=NULL;
		}
		cin>>data;
		if (data!=-1)
		{
			temp->right=new BinaryTreeNode<int>(data);
			pending.push(temp->right);
		}else{
			temp->right=NULL;
		}
	}
	return root;
}
void inorder(BinaryTreeNode<int>*root , vector<int>&in)
{
	if(!root) return;
	inorder(root->left , in);
	in.push_back(root->data);
	inorder(root->right , in);

}
bool isTripletPresent(BinaryTreeNode<int> *root)
{ 
 vector<int> in;
 inorder(root , in);
 for (int i = 0; i < in.size(); ++i)
 {
 	int start=i+1;
 	int end=in.size()-1;
 	while(start<end)
 	{
 		if ((in[i]+in[start]+in[end])>0)
 		{
 			end--;
 		}else if((in[i]+in[start]+in[end])<0)
 		{
 			start++;
 		}else{
 			return true;
 		}
 	}
 }
 return false;
}
int main()
{
	BinaryTreeNode<int>*root=takeInput();
	cout<<isTripletPresent(root);
}