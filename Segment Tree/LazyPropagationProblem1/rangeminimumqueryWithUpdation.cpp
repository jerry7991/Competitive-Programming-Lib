#include<iostream>
using namespace std;
void buildSegementTree(int *arr ,int * tree , int start, int end ,int treeNode)
{	
	if (start==end)
	{
		tree[treeNode]=arr[start];
		return;
	}
	//else we need to travers in both subtree 
	int mid=(start+end)/2;
	//left subtree
	buildSegementTree( arr ,  tree ,  start, mid ,2*treeNode);
	//right subtree
	buildSegementTree( arr ,  tree ,  mid+1, end ,2*treeNode+1);

	tree[treeNode]= min(tree[treeNode*2] , tree[treeNode*2+1] );	//store min
}
void updateSegementLazyTree(int *tree , int *lazy , int low , int high  , int startR , int endR , int incr_value , int treeNode)
{
	//base case 
	if (low>high)
	{
		return ;
	}
	//before using current node we will update first lazy propagate
	if (lazy[treeNode] !=0)
	{
		//that's means we have an painding updation
		//let's update currespond node from tree and shift this node to their child
		tree[treeNode]	+=	lazy[treeNode];
		//check weather current node is leafe or not
		if (low != high)	//that's means we are at non leaf node so we have to transfer our update to their leafe
		{
			lazy[treeNode*2]	+= lazy[treeNode];//left child
			lazy[treeNode*2+1]	+= lazy[treeNode];//right child
		}
		//and now we have to make our current lazy[node]=0 because we are done with updation so make it 0
		lazy[treeNode]=0;
	}

	//now we have 3 condition
	//condition1:- if our current Interval i.e. [low , high] is completely out of given interval[startR , endR]
	if (startR >high || endR < low)
	{
		//just return we have nothing to do
		return;
	}
	//condition2:- if our current interval[low , high] lies completely inside of given interval[startR , endR]
	if (startR <= low && high <=endR)
	{
		//increment given update
		tree[treeNode]	+= incr_value;
		//and let's do append this update with the leafe of current node in lazy tree so that whenever we reache this
		//we check first painding updation and complete them and then do something
		if (low != high)
		{
			//that's means we are at non-leafe node so let's append this incr_value to their left child and right child
			lazy[treeNode*2]	+= incr_value;//left child
			lazy[treeNode*2+1]	+= incr_value;//right child
		}
		return;
	}
	//conditon3:- if our current interval[low,high] lies partily inside and outside of given interval[startR , endR]
	//we have to go left subtree and right subtree
	int mid=(low+high)/2;
	//left subtree
	updateSegementLazyTree( tree ,  lazy ,  low ,  mid  ,  startR ,  endR ,  incr_value ,  treeNode*2);
	updateSegementLazyTree( tree ,  lazy ,  mid+1,  high ,  startR ,  endR ,  incr_value ,  treeNode*2+1);

	//while poping from stack we are going to save our modifed tree
	tree[treeNode]=min(tree[treeNode*2] , tree[treeNode*2+1]);
}
int getAnswer(int *tree ,int * lazy , int low , int high , int startR ,int endR, int treeNode)
{
	//base case1:- If current interval is completely outside of given intercval[startR , endR]
	if (low >endR || high < startR)
	{
		return INT_MAX;
	}
	//if we have found the interval but before using this interval we need to check weather this interval has any painding updation or not
		if (lazy[treeNode] !=0)
		{
			//now we have to update our painding updataion ok!
			tree[treeNode]	+=	lazy[treeNode];
			//now we need to shift this painding updatation to leafe of current node
			//check is it non-leafe node?
			if (low != high)
			{
				//it is leaf node
				//apend update to their left and right leafe;
				lazy[treeNode*2]	+=	lazy[treeNode];	//left child
				lazy[treeNode*2+1]	+= lazy[treeNode];
			}
			//now we have to clear our update record currespond to current node because we have done completely
			lazy[treeNode]	=0;
		}
	//base case2:- If current interval is completely inside of given interval[startR , endR]
	if (low >= startR && high <=endR)
	{
		//return what i updated or not
		return tree[treeNode];
	}
	//base case 3:-we need to go both side , left subtree and right subtree
	int mid=(low+high)/2;
	//min of left subtree
	int leftMin=getAnswer(tree , lazy , low , mid , startR , endR , treeNode*2);
	//min of right subtree
	int rightMin=getAnswer(tree , lazy , mid+1 , high , startR , endR , treeNode*2+1);

	return min(leftMin , rightMin);
}
int main()
{
	int n , nQuery;
	cin>>n>>nQuery;
	int *arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	//make a tree
	int *tree=new int[3*n]();
	buildSegementTree(arr , tree , 0, n-1 , 1);
	// for (int i = 0; i < 3*n; ++i)
	// {
	// 	cout<<tree[i]<<endl;
	// }
	// cout<<"tree after updation\n";
	int *lazy=new int[3*n]();
	while(nQuery--)
	{
		char ch;
		cin>>ch;
		if (ch=='u')
		{
			int startR,endR,incr_value;
			cin>>startR>>endR>>incr_value;
			updateSegementLazyTree( tree ,  lazy ,  0 ,  n-1 ,  startR-1 ,  endR-1 ,  incr_value ,  1);
			// for (int i = 0; i < 3*n; ++i)
			// {
			// 	cout<<tree[i]<<endl;
			// }
			// cout<<"lazy tree"<<endl;
			// for (int i = 0; i < 3*n; ++i)
			// {
			// 	cout<<lazy[i]<<endl;
			// }
		}else{
			int startR,endR;
			cin>>startR>>endR;
			int answer=getAnswer(tree , lazy , 0 , n-1 , startR-1 , endR-1 , 1);
			cout<<answer<<endl;
		}
	}
}