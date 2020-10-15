#include <iostream>
#include <queue>
using namespace std;
template <typename T> class BST
{
public:
	BST<T> * left;
	BST<T> * right;
	T data;
	BST(T data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
BST<int>* Build(int *arr , int start , int end)
{
	if (start==end)
	{
		BST<int> *root=new BST<int>(arr[start]);
		return root;
	}
	int mid=(start+end)/2;
	BST<int> *root=new BST<int>(arr[mid]);
	root->left=Build(arr , start , mid-1);
	root->right=Build(arr , mid+1 , end);
	return root;
}
void print(BST<int> *root)
{
	queue<BST<int>*>pending;
	pending.push(root);
	pending.push(NULL);
	while(pending.size())
	{
		BST<int> * temp=pending.front();
		pending.pop();
		if (!temp)
		{
			if (pending.size())
			{
				pending.push(NULL);
				cout<<endl;
			}
		}else{
			cout<<temp->data<<" ";
			if (temp->left)
			{
				pending.push(temp->left);
			}
			if (temp->right)
			{
				pending.push(temp->right);
			}
		}
	}
}
void Preorder(BST<int>*root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<(*root).data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	BST<int>*root=Build(arr , 0 , n-1);
	print(root);
	cout<<"Preorder :\n";
	Preorder(root);

}