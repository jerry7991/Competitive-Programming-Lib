//Build tree with given inorder and Pre order
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
void printTree(TreeNode<int>*root)
{
	queue<TreeNode<int>*>output;
	output.push(root);
	output.push(NULL);
	while(output.size()!=0)
	{
		TreeNode<int> *temp=output.front();
		output.pop();
		if (!temp)
		{
			if (output.size()!=0)
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
TreeNode<int> * BuildTree(int * inOrder ,int * preOrder ,int sIn , int eIn , int sPre , int ePre)
{
	if (sIn>eIn || sPre>ePre)
	{
		return NULL;
	}
	//now find the root
	int rootData=preOrder[sPre];//root are at the start index in preorder(Root,left,right)
	//now find the position in of rootData in inOrder
	int index=-1;
	for(int i=sIn ; i<=eIn  ; i++)
	{
		if (inOrder[i]==rootData)
		{
			index=i;
			break;
		}
	}
	if (index==-1)
	{
		cout<<"Bad input formate"<<endl;
		return NULL;
	}
	TreeNode<int>*root=new TreeNode<int>(rootData);
	//construct left subtree
	int length=index-sIn;
	root->left=BuildTree(inOrder ,preOrder , sIn ,  index-1 ,  sPre+1 ,  sPre+length);
	root->right=BuildTree(inOrder ,preOrder , index+1 , eIn ,  sPre+length+1 ,  ePre);
	return root;
}
int main()
{
	int n;
	cin>>n;
	int *inOrder=new int[n];
	int *preOrder=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>*(inOrder+i);
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>*(preOrder+i);
	}
	TreeNode<int> *root=BuildTree(inOrder , preOrder , 0 , n-1 , 0 , n-1);
	printTree(root);
	return 0;
}