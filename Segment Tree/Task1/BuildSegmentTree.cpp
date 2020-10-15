#include <iostream>
using namespace std;
void buildSegmentTree(int *arr , int *tree , int start , int end , int treeNode)
{
	if(start==end)
	{
		tree[treeNode]=arr[start];
		return;
	}
	//else
	//we need to travers in left or tree and right of tree
	int mid=(start+end)/2;
	buildSegmentTree(arr , tree , start , mid , treeNode*2);
	buildSegmentTree(arr , tree , mid+1 , end , treeNode*2+1);
	tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];//left child + right child sum
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
	int *tree=new int[2*n];
	buildSegmentTree(arr , tree , 0 , n-1 ,1);
	for (int i = 1; i <=2*n; ++i)
	{
		cout<<tree[i]<<endl;
	}
}