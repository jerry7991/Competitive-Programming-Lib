#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T> class BinaryTreeNode
{
	public:
		BinaryTreeNode<T> *left;
		BinaryTreeNode<T> *right;
		T data;
		BinaryTreeNode (T data)
		{
			this->data=data;
		}
};
vector<BinaryTreeNode<int> *> constructTrees(int start, int end)
{
 vector<BinaryTreeNode<int>*>nodeList;
 if (start>end)
 {
 	nodeList.push_back(NULL);
 	return nodeList;
 }
 //let's iterate all value form start to end for making left subtreee and right subtree
 for (int i = start; i <= end; ++i)
 {
 	vector<BinaryTreeNode<int>*>leftSubtree=constructTrees(start , i-1);
 	vector<BinaryTreeNode<int>*>rightSubtree=constructTrees(i+1,end);
 	//now iterate left subtree and right subtree and connect them in root node
 	for (int j = 0; j < leftSubtree.size(); ++j)
 	{
 		BinaryTreeNode<int>*left=leftSubtree[j];
 		for(int k=0 ; k<rightSubtree.size() ; ++k)
 		{
 			BinaryTreeNode<int>*right=rightSubtree[k];
 			//make a node of root data of i
 			BinaryTreeNode<int>*root=new BinaryTreeNode<int>(i);
 			//attache each left as left subtree of current root node
 			root->left=left;
 			//attache each right as right subtree of current root node
 			root->right=right;
 			nodeList.push_back(root);
 		}
 	}
 }
 return nodeList;
}
void preorder(BinaryTreeNode<int> *root)
{
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void print(BinaryTreeNode<int>*root)
{
	queue<BinaryTreeNode<int>*>pending;
	pending.push(root);
	pending.push(NULL);
	while(pending.size())
	{
		BinaryTreeNode<int>*temp=pending.front();
		pending.pop();
		if (!temp)
		{
			if (pending.size())
			{
				pending.push(NULL);cout<<endl;
			}
		}else{
			cout<<temp->data<<" ";
			if(temp->left)	 pending.push(temp->left);
			if(temp->right)	pending.push(temp->right);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int start=1,end=n;
	vector<BinaryTreeNode<int>*> BST=constructTrees(start , end);
	for (int i = 0; i < BST.size(); ++i)
	{
		cout<<" TREE "<<i+1<<endl;
		print(BST[i]);
		cout<<endl;
	}
}