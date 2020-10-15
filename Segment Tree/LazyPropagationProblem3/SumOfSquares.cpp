#include <iostream>
using namespace std;
struct TreeNode
{
	int squareSum;
	int sum;
};
struct LazyNode
{
	int value;
	int type;	
};
void buildSegementTree(int * arr ,TreeNode* tree , int start , int end, int treeIndex)
{
	//base case:-
	if (start==end)
	{
		tree[treeIndex].sum = arr[start];
		tree[treeIndex].squareSum = arr[start]*arr[start];
		return;
	}
	int mid=(start+end)/2;
	//recursive call on left sub tree
	buildSegementTree(arr , tree , start , mid , treeIndex*2);
	//recursive call on right sub tree
	buildSegementTree(arr , tree , mid+1 , end , treeIndex*2+1);

	//while poping function from stack we are going to save the answer for each particular treeIndex
	tree[treeIndex].squareSum = tree[treeIndex*2].squareSum + tree[treeIndex*2+1].squareSum;
	tree[treeIndex].sum = tree[treeIndex*2].sum + tree[treeIndex*2+1].sum;
}
void updateSegmentTree(int * arr ,TreeNode * tree ,LazyNode * lazyTree , int left , int right , int start , int end ,int treeIndex, int updateValue ,int choice)
{
	//before accessing the current node of tree we need to check weather current node has any pending operation or not
	if (lazyTree[treeIndex].type!=0)
	{
		//that's means we have pending operation ,so now let's complete this operation to their type
		if (lazyTree[treeIndex].type==1)
		{
			// so we need to set all numbers with indices in [start,end] to updateValue
			//update current node currespond to tree
			tree[treeIndex].sum	=	(right-left+1) * lazyTree[treeIndex].value;//if we assign x in start to end then our total sum will be (end-start+1)*x
			tree[treeIndex].squareSum  = (right-left+1) * (lazyTree[treeIndex].value * lazyTree[treeIndex].value);
			
			//now we have done with current node ,now instead of updating all child node let's append this updation with their child
			if (left != right)
			{
				//that's means we are at a non-leaf node
				lazyTree[treeIndex*2].value = lazyTree[treeIndex].value;	//left child value
				lazyTree[treeIndex*2].type = lazyTree[treeIndex].type;	//left child choice
				lazyTree[treeIndex*2+1].value = lazyTree[treeIndex].value;//right child value
				lazyTree[treeIndex*2+1].type = lazyTree[treeIndex].type;//right child choice
			}
			//now we have done with current node completely so let's clear our update history
			lazyTree[treeIndex].value=0;
			lazyTree[treeIndex].type=0;//nothing to do
		}
		else if(lazyTree[treeIndex].type==2)
		{
			// so we need to add all numbers with indices in [start,end] to updateValue
			//update current node currespond to tree
			tree[treeIndex].squareSum += 2 * lazyTree[treeIndex].value * tree[treeIndex].sum + (lazyTree[treeIndex].value * lazyTree[treeIndex].value) *(right-left+1);
			tree[treeIndex].sum += lazyTree[treeIndex].value * (right-left+1);

			//now we have done with current node ,now instead of updating all child node let's append this updation with their child
			if (left != right)
			{
				//that's means we are at a non-leaf node
				lazyTree[treeIndex*2].value += lazyTree[treeIndex].value;	//left child value
				lazyTree[treeIndex*2].type = lazyTree[treeIndex].type;	//left child choice
				lazyTree[treeIndex*2+1].value += lazyTree[treeIndex].value;//right child value
				lazyTree[treeIndex*2+1].type = lazyTree[treeIndex].type;//right child choice
			}
			//now we have done with current node completely so let's clear our update history
			lazyTree[treeIndex].value=0;
			lazyTree[treeIndex].type=0;//nothing to do
		}
	}
	//base case:-
	//we have 3 condition of our current node:-
	//if our current Interval[left,right] lies completely out side the given interval[start,end]
	if (left>end || right < start || left>right)
	{
		//nothing have to do
		return;
	}
	//if current Interval[left,right] lies completely inside of the given interval
	if (left >=start && right <=end)
	{
		if (choice==1)
		{
			// so we need to set all numbers with indices in [start,end] to updateValue
			//update current node currespond to tree
			tree[treeIndex].sum	=	(right-left+1) * updateValue;//if we assign x in start to end then our total sum will be (end-start+1)*x
			tree[treeIndex].squareSum  = (right-left+1) * (updateValue * updateValue);
			
			//now we have done with current node ,now instead of updating all child node let's append this updation with their child
			if (left != right)
			{
				//that's means we are at a non-leaf node
				lazyTree[treeIndex*2].value = updateValue;	//left child value
				lazyTree[treeIndex*2].type = choice;	//left child choice
				lazyTree[treeIndex*2+1].value = updateValue;//right child value
				lazyTree[treeIndex*2+1].type = choice;//right child choice
			}
		}else if(choice==2)
		{
			//update current node currespond to tree
			tree[treeIndex].squareSum += 2 * updateValue * tree[treeIndex].sum + (updateValue * updateValue) *(right-left+1);
			tree[treeIndex].sum += updateValue * (right-left+1);

			//now we have done with current node ,now instead of updating all child node let's append this updation with their child
			if (left != right)
			{
				//that's means we are at a non-leaf node
				lazyTree[treeIndex*2].value += updateValue;	//left child value
				lazyTree[treeIndex*2].type = choice;	//left child choice
				lazyTree[treeIndex*2+1].value += updateValue;//right child value
				lazyTree[treeIndex*2+1].type = choice;//right child choice
			}
		}
		return;
	}
	int mid=(left+right)/2;
	//recursive call on left side
	updateSegmentTree(  arr ,  tree ,  lazyTree ,  left ,  mid ,  start ,  end , treeIndex*2,  updateValue ,choice);
	//recursive call on right side
	updateSegmentTree(  arr ,  tree ,  lazyTree ,  mid+1,  right ,  start ,  end , treeIndex*2+1,  updateValue ,choice);
	//while poping the function from stack ,we are going to save what i have done....Ok!!!!
	//update tree node:-
	tree[treeIndex].sum =tree[treeIndex*2].sum+tree[treeIndex*2+1].sum;
	tree[treeIndex].squareSum =tree[treeIndex*2].squareSum+tree[treeIndex*2+1].squareSum;
}
TreeNode getAnswer(TreeNode* tree ,LazyNode* lazyTree ,int left ,int right , int start ,int end ,int treeIndex)
{
	if (left>right || left >end || right <start)
	{
		TreeNode answer;
		answer.sum=0;
		answer.squareSum=0;
		return answer;
	}
	//before accessing current node we need to check weather current node has any pending operation or not?
	if (lazyTree[treeIndex].type!=0)
	{
		//it has pending operation
		//check which type of operation is pended and complete that operation for current node and append this operation to children of current ndoe
		if (lazyTree[treeIndex].type==1)
		{
			//now we have an operation of set value from interval [left,right], so let's do it;
			tree[treeIndex].sum	=	(right-left+1)*lazyTree[treeIndex].value;
			tree[treeIndex].squareSum = (right-left+1)*(lazyTree[treeIndex].value * lazyTree[treeIndex].value);
			//now shift this operation to their children
			if (left != right)
			{
				//that's means we are at a non-leaf node
				lazyTree[treeIndex*2].value = lazyTree[treeIndex].value;	//left child value
				lazyTree[treeIndex*2].type = lazyTree[treeIndex].type;	//left child choice
				lazyTree[treeIndex*2+1].value = lazyTree[treeIndex].value;//right child value
				lazyTree[treeIndex*2+1].type = lazyTree[treeIndex].type;//right child choice	
			}
		}else if (lazyTree[treeIndex].type==2)
		{
			//now we have an operation to add the updateValue in given interval
			tree[treeIndex].squareSum += 2 * lazyTree[treeIndex].value * tree[treeIndex].sum + (lazyTree[treeIndex].value * lazyTree[treeIndex].value) *(right-left+1);
			tree[treeIndex].sum += lazyTree[treeIndex].value * (right-left+1);
			//now we have done with current node ,now instead of updating all child node let's append this updation with their child
			if (left != right)
			{
				//that's means we are at a non-leaf node
				lazyTree[treeIndex*2].value += lazyTree[treeIndex].value;	//left child value
				lazyTree[treeIndex*2].type = lazyTree[treeIndex].type;	//left child choice
				lazyTree[treeIndex*2+1].value += lazyTree[treeIndex].value;//right child value
				lazyTree[treeIndex*2+1].type = lazyTree[treeIndex].type;//right child choice
			}
		}
		//now we have done with current node completely so let's clear our update history
		lazyTree[treeIndex].value=0;
		lazyTree[treeIndex].type=0;//nothing to do
	}
	//if our current interval[left,right] lies completely inside of given interval[start,end]
	if (left>=start && right <=end)
	{
		return tree[treeIndex];
	}
	//if our current interval[left,right] is partially lies on given interval[start,end] then we have to travel left and right subtree
	int mid=(left+right)/2;
	if (start>mid)
	{
		//need to right travers
		return getAnswer( tree , lazyTree ,mid+1 ,right , start ,end ,treeIndex*2+1);
	}else if (end <=mid)
	{
		//need to left traverse
		return getAnswer( tree , lazyTree ,left ,mid, start ,end ,treeIndex*2);
	}
	TreeNode leftAnswer=getAnswer( tree , lazyTree ,left ,mid, start ,end ,treeIndex*2);
	TreeNode rightAnswer=getAnswer( tree , lazyTree ,mid+1 ,right , start ,end ,treeIndex*2+1);
	TreeNode answer;
	answer.sum = leftAnswer.sum + rightAnswer.sum;
	answer.squareSum = leftAnswer.squareSum + rightAnswer.squareSum;
	return answer;
}
int main()
{
	int x;
	cin>>x;
	int k=1;
	while(k<=x)
	{
		cout<<"Case "<<k<<":"<<endl;k++;
		int n,nQuery;
	cin>>n>>nQuery;
	int * arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	//let's make a tree of treeNode
	TreeNode *tree=new TreeNode[3*n];
	buildSegementTree(arr , tree , 0 , n-1, 1);
	//now let's make a lazy tree of LazyNode
	LazyNode * lazyTree=new LazyNode[3*n];
	for (int i = 0; i < 3*n; ++i)
	{
		lazyTree[i].value=0;
		lazyTree[i].type=0;
	}
	while(nQuery--)
	{
		int choice;
		cin>>choice;
		choice++;
		int treeIndex=1;
		if (choice==1)
		{
		
			int start,end,setValue;
			cin>>start>>end>>setValue;
			updateSegmentTree(arr , tree , lazyTree , 0 , n-1,start-1 , end-1,treeIndex ,setValue , choice);
			// for (int i = 0; i < 3*n; ++i)
			// {
			// 	cout<<i<<"\t sum =  "<<tree[i].sum<<" squareSum = "<<tree[i].squareSum<<endl;
			// 	}
			// for (int i = 0; i < 3*n; ++i)
			// {
			// 	cout<<i<<"\t   "<<lazyTree[i].value<<endl;
			// 	}
		
		}else if(choice==2){

			int start,end,incrementValue;
			cin>>start>>end>>incrementValue;
			updateSegmentTree(arr , tree , lazyTree , 0 , n-1,start-1 , end-1,treeIndex ,incrementValue , choice);
			// for (int i = 0; i < 3*n; ++i)
			// {
			// 	cout<<i<<"\t sum =  "<<tree[i].sum<<" squareSum = "<<tree[i].squareSum<<endl;
			// 	}
			// for (int i = 0; i < 3*n; ++i)
			// {
			// 	cout<<i<<"\t   "<<lazyTree[i].value<<endl;
			// 	}

		}else if(choice==3){
				int start,end;
				cin>>start>>end;
				TreeNode answer=getAnswer(tree , lazyTree , 0 , n-1 , start-1 , end-1 , treeIndex);
				cout<<answer.squareSum<<endl;
		}
	}
	}
	return 0;
}