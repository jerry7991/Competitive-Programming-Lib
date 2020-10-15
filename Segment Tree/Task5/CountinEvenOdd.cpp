#include <iostream>
using namespace std;
struct Node
{
	int nEven;
	int nOdd;
};
void buildSegementTree(int *arr ,Node * tree , int start ,int end, int treeNode)
{
	if (start==end)
	{
		if ( (arr[start] & 1)==0)
		{
			tree[treeNode].nEven=1;
			tree[treeNode].nOdd=0;
		}else{
			tree[treeNode].nOdd=1;
			tree[treeNode].nEven=0;
		}
		return;
	}
	int mid=(start+end)/2;
	//left tree travers 
	buildSegementTree(arr , tree , start , mid , treeNode*2);
	//right tree travers
	buildSegementTree(arr , tree , mid+1 , end ,treeNode*2+1);

	//while poping function from stack we build our segment tree
	Node leftSubTree = tree[treeNode*2];
	Node rightSubTree = tree[treeNode*2+1];
	tree[treeNode].nEven = leftSubTree.nEven + rightSubTree.nEven;
	tree[treeNode].nOdd = leftSubTree.nOdd + rightSubTree.nOdd;
	return;
}
Node getAnswer(Node *tree ,int start , int end , int treeNode ,int left ,int right)
{
	//their is base cases;
	//when our start and end complitely lies out of given interval[left,right]
	if (start > right || end < left)
	{
		Node answer;
		answer.nEven=0;
		answer.nOdd=0;
		return answer;
	}
	//if our start and end complitely lies into given interval[left,right]
	if (start >= left && end <= right)
	{
		return tree[treeNode];
	}
	//other wise we have partialy interval so trace both subtree ,right subtree as wll as left subtree
	int mid = (start+end)/2;
	//left subtree
	Node leftSubTree = getAnswer(tree , start , mid , treeNode*2 , left , right);
	//right subtree
	Node rightSubTree = getAnswer(tree , mid+1 , end , treeNode*2+1 , left ,right);

	Node answer;
	answer.nEven = leftSubTree.nEven + rightSubTree.nEven;
	answer.nOdd = leftSubTree.nOdd + rightSubTree.nOdd;
	return answer;
}
void updateSegementTree(int *arr ,Node * tree , int start , int end , int treeNode ,int index ,int updateValue)
{
	//base case:
	if (start==end)
	{
		arr[index]=updateValue;
		if( (updateValue & 1) ==0)
		{
			tree[treeNode].nEven=1;
			tree[treeNode].nOdd=0;
		}else{
			tree[treeNode].nEven=0;
			tree[treeNode].nOdd=1;
		}
		return;
	}
	int mid=(start+end)/2;
	updateSegementTree(arr , tree , start , mid , treeNode*2 , index , updateValue);
	updateSegementTree(arr , tree , mid+1 ,end , treeNode*2+1 , index , updateValue);

	//while poping the function from the stack we are going to update the value;
	tree[treeNode].nEven = tree[treeNode*2].nEven+tree[treeNode*2+1].nEven;
	tree[treeNode].nOdd = tree[treeNode*2].nOdd+tree[treeNode*2+1].nOdd;
	return;
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
	Node *tree=new Node[4*n];
	buildSegementTree(arr , tree , 0 ,n-1, 1);
	int nQuery;
	cin>>nQuery;
	while(nQuery--)
	{
		int choice,left,right;
		cin>>choice>>left>>right;
		if(choice==0)
		{
			int index=left-1;//because indexing started frm 0
			int updateValue=right;
			updateSegementTree(arr , tree , 0 , n-1 , 1 , index , updateValue);
		}else if (choice==1)
		{
			Node answer=getAnswer(tree , 0 , n-1 , 1 ,left-1 , right-1);
			cout<<answer.nEven<<endl;
		}else{
			//i.e. choice is 2;
			Node answer=getAnswer(tree , 0 , n-1 , 1 ,left-1 , right-1);
			cout<<answer.nOdd<<endl;
		}
	}
}