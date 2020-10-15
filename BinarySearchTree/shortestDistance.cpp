#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T> class BSTNode
{
public:
	BSTNode<T>*left;
	BSTNode<T>*right;
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
	if (data==-1) return NULL;
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
void getPath(BSTNode<int>*root , vector<int> &path , int key)
{
	if (!root)
	{
		return;
	}
	path.push_back(root->data);
	if (root->data==key)
	{
		return;
	}
	if ((root->data)<key)
	{
		getPath(root->right , path , key);
	}else{
		getPath(root->left , path , key);
	}
}
int distanceBetween2(BSTNode<int> *root,int a,int b)
{
	vector<int>pathA;
	getPath(root  , pathA ,a);
	vector<int>pathB;
	getPath(root , pathB ,b);
	for (unsigned int i = 0; i < pathA.size(); ++i)
	{
		cout<<pathA[i]<<" ";
	}
	cout<<endl;
	for (unsigned int i = 0; i < pathB.size(); ++i)
	{
		cout<<pathB[i]<<" ";
	}
	cout<<endl;
	unsigned int i=0;
	while(i<pathA.size() && i<pathB.size() && pathA[i]==pathB[i])
		i++;
	int len=(pathA.size()-i)+(pathB.size()-i);
	return len;
}
int main()
{
	BSTNode<int>*root=takeInput();
	while(1)
	{
	 int a,b;
	 cin>>a>>b;
	 if(a==0 && b==0)	return 0;
	 cout<<distanceBetween2(root,a,b);
	}
}