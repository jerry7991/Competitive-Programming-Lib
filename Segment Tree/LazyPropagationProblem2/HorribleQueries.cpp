#include <iostream>
using namespace std;
typedef long long ll;
void updateSegementLazyTree(ll *tree , ll *lazy , ll low, ll high,ll startR ,ll endR ,ll updateValue ,ll treeNode)
{
	
	//before using current node we need to check weather currentnode has any painding updation or not
	if (lazy[treeNode]!=0)
	{
		//update painding updation
		tree[treeNode]	+=	(high-low+1)*lazy[treeNode];
		//transfer update record to child of current node if child possible
		if (low!=high)
		{
			//that's means child possible
			lazy[treeNode*2]	+= lazy[treeNode];	//append update to left child
			lazy[treeNode*2+1]	+= lazy[treeNode];	//append update to right child
		}
		lazy[treeNode]=0;//remove lazyness of current node
	}
	//if our current interval [low,high] is completely outside of the given Interval[startR,endR]
	if (startR >high || endR <low || low>high)
	{	
		//then we have to ignore those path of tree
		return;
	}
	//if our current interval is completely inside of given interval
	if (low >=startR && high <=endR)
	{
		//first need to update the current node with their painding updation
		tree[treeNode]	+= (high-low+1)*updateValue;
		if (low!=high)
		{
			//that's means we are at the non-leaf node
			lazy[treeNode*2] +=updateValue;	//so append lazyness to their left child
			lazy[treeNode*2+1] +=updateValue;//append lazyness to their right child
		}
		return;
	}
	//partially inside and outside then we have to traverse all sub tree i.e. right subtree and left subtree also
	ll mid=(low+high)/2;
	updateSegementLazyTree(tree ,  lazy ,  low,  mid, startR , endR , updateValue , treeNode*2);
	updateSegementLazyTree(tree ,  lazy ,  mid+1,  high, startR , endR , updateValue , treeNode*2+1);

	//while poping the function from stack ,we are going to save what i have done....Ok!!!!
	//update tree node:-
	tree[treeNode]	= tree[treeNode*2] + tree[treeNode*2+1];	//left sum+rightsum(after updation)
}
ll getAnswer(ll *tree ,ll * lazy , ll low, ll high ,ll startR,ll endR , ll treeNode)
{
	//base case
	if (low>high)
	{
		return 0;
	}
	//completely outside
	if (low >endR || high <startR)
	{
		return 0;
	}
	//before using current node we need to check weather currentnode has any painding updation or not
	if (lazy[treeNode]!=0)
		{
			//i.e. if we would have added x value from low to high then total changes for root node will be (high-low+1)*x
			tree[treeNode]	+= (high-low+1)*lazy[treeNode];
			if (low!=high)
			{
				//if we are at non-leaf node
				lazy[treeNode*2] += lazy[treeNode];	//append updateion process to left tree
				lazy[treeNode*2+1] += lazy[treeNode];//append updation process to right tree
			}
			lazy[treeNode]=0;
		}
	//if our current interval is completely inside of given interval
	if (low >=startR && high <=endR)
	{
		return tree[treeNode];
	}
	//if our current interval is cpartially inside and partially out side of given interval then we need to travers both side left and right too
	ll mid=(low+high)/2;
	if(startR>mid)
	{
		//that's means our start is away from mid so we need to treverse in right subtree
		return getAnswer( tree ,  lazy ,  mid+1, high, startR, endR ,  treeNode*2+1);
	}else if(endR <= mid){
		//that's means our end is so far to mid or equal so need to travers in left subtree
		return getAnswer( tree ,  lazy ,  low, mid, startR, endR ,  treeNode*2);
	}
	ll left=getAnswer( tree ,  lazy ,  low, mid, startR, endR ,  treeNode*2);	//traverse right
	ll right=getAnswer( tree ,  lazy ,  mid+1, high, startR, endR ,  treeNode*2+1);	//and left
	return (left+right);//for any node total sum=(leftTreeSum+rightTreeSum)
}
int main()
{
	int nTestCase;
	cin>>nTestCase;
	while(nTestCase--)
	{
		ll n,nQuery;
		cin>>n>>nQuery;
		ll *tree=new ll[3*n]();
		ll *lazy=new ll[3*n]();
		while(nQuery--)
		{
			int choice;
			cin>>choice;
			if (choice==0)
			{
				ll startR,endR,updateValue;
				cin>>startR>>endR>>updateValue;
				//0:- start index , n-1 end index ,1 treeIndex tree is our segment tree and lazy is our lazy segment tree
				updateSegementLazyTree(tree , lazy , 0, n-1, startR-1 , endR-1 , updateValue , 1);
			for (int i = 0; i < 3*n; ++i)
				{
					cout<<i<<"\t"<<tree[i]<<"\t"<<lazy[i]<<endl;
				}
			}else{
				ll startR,endR;
				cin>>startR>>endR;
				ll answer=getAnswer(tree , lazy , 0, n-1 , startR-1 , endR-1 , 1);
				cout<<answer<<endl;
			}
		}
	}
}