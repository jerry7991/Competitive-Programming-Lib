#include <iostream>
#include <queue>
#include <list>
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
	if (data==-1) return NULL;
	BSTNode<int>*root=new BSTNode<int>(data);
	queue<BSTNode<int>*> pending;
	pending.push(root);
	while(pending.size())
	{
		BSTNode<int> *temp=pending.front();
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
int height(BSTNode<int>*root)
{
	if (!root)
	{
		return 0;
	}
	int lHeight=1+height(root->left);
	int rHeight=1+height(root->right);
	return max(lHeight, rHeight);
}
list<int>* fillLevelArr(BSTNode<int>* root , int n)
{
	list<int> *arr=new list<int>[n+1];
	int level=0;
	// list<int> curr;
	// curr.push_back(root->data);
	// arr[level]=curr;
	//make a queue for level order traversal
	queue<BSTNode<int>*>pending;
	pending.push(root);
	pending.push(NULL);
	level++;
	while(pending.size() && level<(n+1))
	{
		BSTNode<int>*temp=pending.front();
		pending.pop();
		if (!temp)
		{
			if (pending.size())
			{
				pending.push(NULL);
				level++;
				//cout<<endl;
			}
		}else{
			arr[level].push_back(temp->data);
			//cout<<temp->data<<" ";
			if(temp->left)	pending.push(temp->left);
			if(temp->right) pending.push(temp->right);
		}
	}
	//cout<<endl;
	return arr;
}
int main()
{
	BSTNode<int>*root=takeInput();
	int n=height(root);
	list<int> *levelArr=fillLevelArr(root , n);
	for(int i=0 ; i<(n+1) ; i++)
	{
		list<int> curr=levelArr[i];
		list<int>:: iterator itr=curr.begin();
		while(itr!=curr.end())
		{
			cout<<*itr<<" ";
			itr++;
		}
		cout<<endl;
	}
}