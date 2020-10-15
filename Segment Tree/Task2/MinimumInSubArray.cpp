#include <bits/stdc++.h>
using namespace std;
void buildSegementTree(int *arr , int *tree , int start , int end  , int treeNode)
{
	if(start==end)
	{
		tree[treeNode]=arr[start];
		return;
	}
	//else travel in right and left subtree 
	int mid=(start+end)/2;
	buildSegementTree(arr , tree , start , mid , treeNode*2);
	buildSegementTree(arr , tree , mid+1 , end , treeNode*2+1);

	//store while poping from stack
	tree[treeNode]=	(	(tree[treeNode*2]>tree[treeNode*2+1])?	tree[treeNode*2+1] :tree[treeNode*2]	);
}
void updateSegmentTree(int *arr ,int * tree ,int start ,int end ,int treeNode ,int index ,int updateValue)
{
	//base  case
	if(start==end)
	{
		arr[index]=updateValue;
		tree[treeNode]=updateValue;
		return;
	}
	//else search
	int mid=(start+end)/2;
	if (index>mid)
	{
		updateSegmentTree(arr , tree , mid+1 , end , treeNode*2+1 , index , updateValue);
	}else{
		updateSegmentTree(arr ,tree , start , mid , treeNode*2 , index , updateValue);
	}

	//update tree while poping the function from starck
	/*
       tree[treeNode]=(	tree[treeNode*2]>tree[treeNode*2+1]	)? tree[treeNode*2+1]	: tree[treeNode];
     	here was my mistake..................  
     */
    tree[treeNode]=(	tree[treeNode*2]>tree[treeNode*2+1]	)? tree[treeNode*2+1]	: tree[2*treeNode];
}
int getAnswer(int *tree , int start  , int end,int treeNode ,int left ,int right)
{
	//base case
	//when start and end lies completly out of interval
	if (start>right || end <left)
	{
		return INT_MAX;
	}
	//when start and end lies completely inside of given interval
	if (start>=left && end<=right)
	{
		return tree[treeNode];
	}
	//for partialy check for poth left subtree and rightSubtree
	int mid=(start+end)/2;
	int left_tree=getAnswer(tree , start ,mid , treeNode*2 , left , right);
	int right_tree=getAnswer(tree , mid+1 , end , treeNode*2+1	,	left , right);
	return (	(left_tree<right_tree)?left_tree:right_tree	);
}
int main()
{
	int n,nQuery;
	cin>>n>>nQuery;
	int *arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int *tree=new int[4*n];
	buildSegementTree(arr , tree , 0 , n-1 , 1);
	// for (int i = 1; i < 4*n; ++i)
	// {
	// 	cout<<i<<"\t"<<tree[i]<<endl;
	// }
	while(nQuery--)
	{
		char ch;
		cin>>ch;
		if (ch=='q')
		{
			int left , right;
			cin>>left >>right;
			cout<<getAnswer(tree , 0 , n-1,1 ,left-1 , right-1)<<endl;
		}
		if (ch=='u')
		{
			int index,updateValue;
			cin>>index>>updateValue;
			updateSegmentTree(arr , tree ,0 , n-1 , 1 , index-1 , updateValue);
		}
	}
}