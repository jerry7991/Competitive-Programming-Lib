#include <iostream>
#include <stack>
#include <queue>
using namespace std;
template <typename T> class bst
{
public:
	bst<T> *left;
	bst<T> *right;
	T data;
	bst(T data)
	{
		this->data=data;
	}
};
bst<int> * takeInput()
{
	int data;
	cin>>data;
	if(data==-1)return NULL;
	bst<int>*root=new bst<int>(data);
	queue<bst<int>*> pending;
	pending.push(root);
	while(pending.size())
	{
		bst<int>*temp=pending.front();
		pending.pop();
		cin>>data;
		if(data!=-1)
		{
			temp->left=new bst<int>(data);
			pending.push(temp->left);
		}else{
			temp->left=NULL;
		}
		cin>>data;
		if(data!=-1)
		{
			temp->right=new bst<int>(data);
			pending.push(temp->right);
		}else{
			temp->right=NULL;
		}
	}
	return root;
}
void inorder(bst<int> *root)
{
	stack<bst<int>*> curr;
	bst<int>*temp;
	temp=root;
	while(curr.size() || temp!=NULL)//stack might be empty while printing the root of the tree but not temp will be null
	{
	//go deep to left till find null
	 while(temp)
	 {
		curr.push(temp);
		temp=temp->left;
	 }
	 //stack has left most child at the top
	 temp=curr.top();
	 //now remove the printed data
	 curr.pop();
	 cout<<temp->data<<" ";
	 //and go for right of current leftMost
	 temp=temp->right;
	}
}
int main()
{
	bst<int>*root=takeInput();
	inorder(root);
}