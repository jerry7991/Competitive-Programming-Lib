#include <iostream>
#include <queue>
#define si startIndexOfInorder
#define ei endIndexOfInorder
#define sp startIndexOfPostOrder
#define ep endIndexOfPostOrder
using namespace std;
int *inOrder;
int *postOrder;
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
TreeNode<int> * BuildTree(int si , int ei , int sp , int ep)
{
	if(si>ei || sp>ep)
	{
		return NULL;
	}
	int rootData=postOrder[ep] , index=-1;
	for(int i=si ; i<=ei ; i++)
	{
		if (inOrder[i]==rootData)
		{
			index=i;
		}
	}
	if (index==-1)
	{
		cout<<"Bad input sequance! Try right once";
		return NULL;
	}
	int length=index-si;
	TreeNode<int>*root=new TreeNode<int>(rootData);
	root->left=BuildTree(si , index-1, sp , sp+length-1);
	root->right=BuildTree(index+1 , ei , sp+length , ep-1);
	return root;
}
void printTree(TreeNode<int> *root)
{
	queue<TreeNode<int>*> output;
	output.push(root);
	output.push(NULL);
	while(output.size())
	{
		TreeNode<int>*temp=output.front();
		output.pop();
		if (!temp)
		{
			if (output.size())
			{
				output.push(NULL);
				cout<<endl;
			}
		}else{
			cout<<temp->data<<" ";
			if (temp->left)
			{
				output.push(temp->left);
			}
			if (temp->right)
			{
				output.push(temp->right);
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	inOrder=new int[n];
	postOrder=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>*(postOrder+i);
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>*(inOrder+i);
	}
	TreeNode<int> *root=BuildTree(0 , n-1 , 0 ,n-1);
	printTree(root);
}