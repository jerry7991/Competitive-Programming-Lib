#include <iostream>
#include <queue>
#include <vector>
#define BTN BinaryTreeNode
using namespace std;
template <typename T> class BinaryTreeNode
{
public:
	BTN<T> *left;
	BTN<T> *right;
	T data;
	BTN(T data)
	{
		this->data=data;
	}
	~BTN()
	{
		if (left)
		{
			delete left;
		}
		if (right)
		{
			delete right;
		}
	}
};
BTN<int>* takeInput()
{
	int data;
	cin>>data;
	if(data==-1) return NULL;
	BTN<int>*root=new BTN<int>(data);
	queue<BTN<int>*> pending;
	pending.push(root);
	while(pending.size())
	{
		BTN<int>*temp=pending.front();
		pending.pop();
		cin>>data;
		if(data!=-1)
		{
			temp->left=new BTN<int>(data);
			pending.push(temp->left);
		}else{
			temp->left=NULL;
		}
		cin>>data;
		if(data!=-1)
		{
			temp->right=new BTN<int>(data);
			pending.push(temp->right);
		}else{
			temp->right=NULL;
		}
	}
	return root;
}
void print(BTN<int>*root)
{
	queue<BTN<int>*> pending;
	pending.push(root);
	pending.push(NULL);
	while(pending.size())
	{
		BTN<int>*temp=pending.front();
		pending.pop();
		if(!temp)
		{
			if(pending.size())
			{
				pending.push(NULL);
				cout<<endl;
			}
		}else{
			cout<<temp->data<<" ";
			if(temp->left) pending.push(temp->left);
			if(temp->right) pending.push(temp->right);
		}
	}
}
void getInorder(BTN<int>*root ,vector<int>& inorder)
{
	if(!root) return;
	getInorder(root->left , inorder);
	inorder.push_back(root->data);
	getInorder(root->right , inorder);
}
void merge(vector<int> v1 , vector<int> v2 , int *arr)
{
	unsigned int i=0 , j=0 , k=0;
	while(i<v1.size() && j<v2.size())
	{
		if(v1[i]<v2[j])
		{
			arr[k++]=v1[i++];
		}else{
			arr[k++]=v2[j++];
		}
	}
	while(i<v1.size())
	{
		arr[k++]=v1[i++];
	}
	while(j<v2.size())
	{
		arr[k++]=v2[j++];
	}
}
BTN<int>* buildTree(int *arr , int start , int end)
{
	if (start>end)
	{
		return NULL;
	}
	int mid=(start+end)/2;
	BTN<int>*root=new BTN<int>(arr[mid]);
	root->left=buildTree(arr , start , mid-1);
	root->right=buildTree(arr , mid+1 , end);
	return root;
}
BinaryTreeNode<int>* printMergeTrees( BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2)
{
	vector<int> inorder1;
	vector<int> inorder2;
	getInorder(root1 , inorder1);
	getInorder(root2 , inorder2);
	int *mInorder=new int[inorder1.size()+inorder2.size()];
	int n=inorder1.size()+inorder2.size();
	merge(inorder1 , inorder2 , mInorder );
	BTN<int>*root=buildTree(mInorder,0,n-1);
	return root;
}
int main()
{
	BTN<int> *root1=takeInput();
	BTN<int> *root2=takeInput();
	BTN<int> *root=printMergeTrees(root1 , root2);
	print(root);
}