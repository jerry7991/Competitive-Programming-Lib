#include<bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
	int Max;
	int sMax;
};
void buildSegementTree(int *arr ,Node * tree ,int start ,int end ,int treeIndex)
{
	//base case
	if(start==end)
	{
		tree[treeIndex].Max=arr[start];
		//initially one element has no second max so
		tree[treeIndex].sMax=INT_MIN;
		return ;
	}
	//other wise traverse in left sub tree and right sub tree
	int mid=(start+end)/2;
	//left subtree will go through like
	buildSegementTree(arr , tree , start , mid , treeIndex*2);
	//right subtree will go though like 
	buildSegementTree(arr , tree , mid+1 , end , treeIndex*2+1);

	//while poping function from stack we are filling our tree element
	Node leftTree=tree[2*treeIndex];
	Node rightTree=tree[treeIndex*2+1];
	
	tree[treeIndex].Max= max(leftTree.Max , rightTree.Max);
	tree[treeIndex].sMax=min(	max(leftTree.Max , rightTree.sMax) , max(leftTree.sMax , rightTree.Max)	);
	return;
}
void updateSegmentTree(int *arr , Node *tree , int start , int end, int treeIndex, int index , int updateValue)
{
	if(start==end)
	{
		tree[treeIndex].Max=updateValue;//because single value is itselft greater than other value which even doesn't exist
		tree[treeIndex].sMax=INT_MIN;
		arr[index]=updateValue;
		return;
	}
	int mid=(start+end)/2;
	//find the tree in which index can lies
	if(index<=mid)
    {
		//travers in left sub tree
		updateSegmentTree(arr , tree , start , mid , treeIndex*2 , index , updateValue);
    }else{
	//travers in right sub tree
	updateSegmentTree(arr , tree , mid+1 ,end,treeIndex*2+1 , index , updateValue);
    }
	
	//while poping function from stack we are going to update our tree
	Node leftTree=tree[treeIndex*2];
	Node rightTree=tree[treeIndex*2+1];

	//which subtree has max value that will be mine max value for root node
	tree[treeIndex].Max= max(leftTree.Max  , rightTree.Max);
	//which subtree has max which not include as max value for root node will be our second max
	tree[treeIndex].sMax=min(	max(leftTree.Max , rightTree.sMax) , max(leftTree.sMax , rightTree.Max)	);
	return;
}
Node getAnswer(Node *tree , int start , int end , int treeIndex , int left , int right)
{
	//base case
	//when our interval reached completely out of given interval
	if (start>right || end<left)
	{
		Node answer;
		answer.Max=INT_MIN;
		answer.sMax=INT_MIN;
		return answer;
		//return -1;
	}
	//when our interval completely inside of given interval
	if(start >=left && end <=right)
	{
		return tree[treeIndex];
	}
	//other is our interval lies partialy inside in our interval
	int mid=(start+end)/2;
	Node answer1=getAnswer(tree , start , mid , treeIndex*2 , left , right);
	Node answer2=getAnswer(tree , mid+1 , end , treeIndex*2+1 , left , right);
	Node answer;
	answer.Max=max(answer1.Max , answer2.Max);
	answer.sMax=min(	max(answer1.Max , answer2.sMax) , max(answer1.sMax , answer2.Max)	);
	return answer;
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
	Node *tree=new Node[3*n];	//because 2*n+1 possible so index can be jump at most 2n+n
	buildSegementTree(arr , tree , 0 , n-1 , 1);
	// for (int i = 0; i < 3*n; ++i)
	// {
	// 	cout<<i<<" -> ["<<tree[i].Max<<" , "<<tree[i].sMax<<" ]"<<endl;
	// }
	int nQuery;
	cin>>nQuery;
	while(nQuery--)
	{
		char ch;
		cin>>ch;
		if(ch=='Q')
		{
			int left,right;
			cin>>left>>right;
			Node answer=getAnswer(tree , 0 , n-1 , 1 ,left-1,right-1);
			cout<<answer.Max+answer.sMax<<endl;
		}
		if(ch=='U')
		{
			int index,updateValue;
			cin>>index>>updateValue;
			updateSegmentTree(arr , tree , 0, n-1 , 1 , index-1 , updateValue);
		}
	}
	return 0;
}