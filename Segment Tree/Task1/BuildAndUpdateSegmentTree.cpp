#include <iostream>
using namespace std;
void buildSegmentTree(int *arr , int *tree , int start , int end , int treeNode)
{
	if (start==end)
	{
		tree[treeNode]=arr[start];
		return;
	}
	//else we have to travel left sub tree and right sub tree
	int mid=(start +end )/2;
	buildSegmentTree(arr , tree , start , mid , treeNode*2);
	buildSegmentTree(arr , tree , mid+1 , end , treeNode*2+1);

	//update tree while poping function from stack
	tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];
}
void update(int *arr,int *tree , int start , int end , int treeNode , int index ,int updateValue)
{
	if(start==end)
	{
		arr[index]=updateValue;
		tree[treeNode]=updateValue;
		return ;
	}
	int mid=(start+end)/2;
	if (index>mid)
	{
		//need to traverse in right sub tree
		update(arr , tree , mid+1 , end, 2*treeNode+1 , index , updateValue);
	}else{
		//need to traverse in left subtree
		update(arr , tree , start , mid , 2*treeNode , index , updateValue);
	}
	//while poping from stack we are going to update the interval value cause of new update;
	tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];
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
	buildSegmentTree(arr , tree , 0 ,n-1 , 1);
	for (int i = 1; i < 2*n+1; ++i)
	{
		cout<<tree[i]<<endl;
	}
	cout<<"\n\n";
	int index,updateValue;
	cin>>index>>updateValue;
	update(arr,tree , 0 , n-1 , 1 , index , updateValue);
	for (int i = 1; i < 2*n+1; ++i)
	{
		cout<<tree[i]<<endl;
	}
}