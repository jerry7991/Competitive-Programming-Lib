#include <iostream>
using namespace std;
void buildSegmentTree(int *arr , int *tree , int start ,int end ,int treeNode )
{
	//base case 
	if (start==end)
	{
		tree[treeNode]=arr[start];
		return;
	}
	//let's figure out mid
	int mid=(start+end)/2;
	//traverse in left subtree
	buildSegmentTree(arr , tree , start , mid , treeNode*2);
	buildSegmentTree(arr , tree ,mid+1 , end , treeNode*2+1);

	//while poping the function from stack we make our tree
	tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];
}
void updateSegmentTree(int *arr , int *tree  , int start , int end ,int treeNode,int index , int updateValue)
{
	//base case 
	if (start==end)
	{
		arr[index]=updateValue;
		tree[treeNode]=updateValue;
		return;
	}
	//else we have to travers in the tree;
	int mid=(start+end)/2;
	if (index>mid)
	{
		//need to traverse right subtree
		updateSegmentTree(arr , tree , mid+1 , end ,treeNode*2+1,index , updateValue );
	}else{
		//need to traverse in left subtree
		updateSegmentTree(arr , tree ,start,mid , treeNode*2 , index , updateValue);
	}
	//update value while poping the function
	tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];
}
int getOutput(int *arr , int *tree ,int start , int end , int treeNode , int left , int right)
{
	//completely outside
	if (start>right || end <left)
	{
		return 0;
	}
	//completely inside
	if(start>=left && end<=right)
	{
		return tree[treeNode];
	}
	//partially inside & partially outside
	int mid=(start+end)/2;
	int ans1=getOutput(arr , tree , start , mid , treeNode*2 , left  ,right);
	int ans2=getOutput(arr ,tree , mid+1 ,end , treeNode*2+1 , left ,right);
	return (ans1+ans2);
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
	int *tree=new int[4*n];
	//let's first of build our tree
	buildSegmentTree(arr , tree , 0 , n-1 ,1 );
	// for (int i = 0; i <4*n; ++i)
	// {
	// 	cout<<tree[i]<<endl;
	// }

	int nQuery;
	cin>>nQuery;
	while(nQuery--)
	{
		char ch;
		cin>>ch;
		if(ch=='U')
		{
			int index,updateValue;
			cin>>index>>updateValue;
			updateSegmentTree(arr , tree , 0 , n-1 ,1, index , updateValue);
		}
		if(ch=='Q')
		{
			int left,right;
			cin>>left>>right;
			cout<<getOutput(arr , tree , 0 , n-1 , 1,left , right);
		}
	}
}