#include <iostream>
#include <queue>
using namespace std;
template<typename T>
class TreeNode
{
public:
	TreeNode<T> * left;
	TreeNode<T> *right;
	T data;
	TreeNode(T data)
	{
		this->data=data;
	}
};
TreeNode<int> * takeInput(bool isRoot=true , int parent=-1 , bool isLeft=false)
{
	if (isRoot)
	{
		cout<<"Enter Root Data : ";
	}else{
		if(isLeft)
		{
			cout<<"Enter left node of "<<parent<<" : ";
		}else{
			cout<<"Enter right node of "<<parent<<" : ";
		}
	}
	int data;
	cin>>data;
	if (data==-1)
	{
		return NULL;
	}
	TreeNode<int>* root=new TreeNode<int>(data);
	 TreeNode<int> * leftSubTree=takeInput(false , data ,true);
	 TreeNode<int> * rightSubTree=takeInput( false , data , false);
	root->left=leftSubTree;
	root->right=rightSubTree;
	return root;
}
void printTree(TreeNode<int>* root)
{
	if (root==NULL)
	{
		return;
	}
	cout<<root->data<<" : ";
	if (root->left)
	{
		cout<<" L "<<root->left->data<<" , ";
	}
	if (root->right)
	{
		cout<<" R "<<root->right->data;
	}
	cout<<endl;
	printTree(root->left);
	printTree(root->right);
}
void printPostOrder(TreeNode<int> *root)
{
	if (!root)
	{
		return;
	}
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}
TreeNode<int> * takeInputDirect()
{
	TreeNode<int> *root;
	int rootData;
	cin>>rootData;
	root=new TreeNode<int>(rootData);
	queue<TreeNode<int> *> input;
	input.push(root);
	while(!input.empty())
	{
		TreeNode<int> *temp=input.front();
		input.pop();
		int data;
		cin>>data;
		if(data!=-1)
		{
			temp->left=new TreeNode<int>(data);
			input.push(temp->left);
		}else{
			temp->left=NULL;
		}
		int datar;
		cin>>datar;
		if(datar!=-1)
		{
			temp->right=new TreeNode<int>(datar);
			input.push(temp->right);
		}else{
			temp->right=NULL;
		}
	}
	return root;

}
int main()
{
	TreeNode<int> *root;
	root=takeInput();
	cout<<"Your tree is :"<<endl;
	printTree(root);
	cout<<"Post order is :"<<endl;
	printPostOrder(root);
	cout<<"\n Enter Direct input"<<endl;
	TreeNode<int>*root2;
	root2=takeInputDirect();
	cout<<"Your Direct tree is  : \n";
	printTree(root2);
}