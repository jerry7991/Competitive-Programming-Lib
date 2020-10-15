#include <iostream>
using namespace std;
struct Worrior
{
	int aValue;
	int bValue;
};
struct Node
{
	int aValue;
	int bValue;
	int index;
};
void buildSegementTree(Worrior* arr ,Node* tree , int start , int end , int treeNode)
{
	if(start==end)
	{
		tree[treeNode].aValue=arr[start].aValue;
		tree[treeNode].bValue=arr[start].bValue;
		tree[treeNode].index=start;
		return;
	}
	int mid=(start+end)/2;
	buildSegementTree(arr , tree , start , mid , treeNode*2);
	buildSegementTree(arr , tree , mid+1 , end , treeNode*2+1);

	Node leftSubTree = tree[treeNode*2];
	Node rightSubTree = tree[treeNode*2+1];
	if (leftSubTree.aValue == rightSubTree.aValue)
	{
		if (leftSubTree.bValue == rightSubTree.bValue)
		{
			if (leftSubTree.index < rightSubTree.index)
			{
				tree[treeNode].aValue = leftSubTree.aValue;
				tree[treeNode].bValue = leftSubTree.bValue;
				tree[treeNode].index = leftSubTree.index;
			}else{
				tree[treeNode].aValue = rightSubTree.aValue;
				tree[treeNode].bValue = rightSubTree.bValue;
				tree[treeNode].index = rightSubTree.index;
			}
		}else{
			if(leftSubTree.bValue < rightSubTree.bValue)
			 {
				tree[treeNode].aValue = leftSubTree.aValue;
				tree[treeNode].bValue = leftSubTree.bValue;
				tree[treeNode].index = leftSubTree.index;
			 }else{
				tree[treeNode].aValue = rightSubTree.aValue;
				tree[treeNode].bValue = rightSubTree.bValue;
				tree[treeNode].index = rightSubTree.index;
			 }
		}
	}else{
		if(leftSubTree.aValue > rightSubTree.aValue)
		{
			tree[treeNode].aValue = leftSubTree.aValue;
			tree[treeNode].bValue = leftSubTree.bValue;
			tree[treeNode].index = leftSubTree.index;
		}else{
			tree[treeNode].aValue = rightSubTree.aValue;
			tree[treeNode].bValue = rightSubTree.bValue;
			tree[treeNode].index = rightSubTree.index;
		}
	}
	return;
}
Node getAnswer(Node *tree , int start  ,int end ,  int treeNode ,int left  ,int right)
{
	if (start > right || end <left)
	{
		Node answer;
		answer.aValue=INT_MIN;
		answer.bValue=INT_MAX;
		answer.index=INT_MAX;
		return answer;
	}
	if (start >=left && end <=right)
	{
		return tree[treeNode];
	}
	int mid=(start+end)/2;
	Node leftSubTree=getAnswer(tree , start , mid , treeNode*2 ,left , right); 
	Node rightSubTree=getAnswer(tree , mid+1 , end,treeNode*2+1 , left , right);
	Node answer;
	if (leftSubTree.aValue == rightSubTree.aValue)
	{
		if (leftSubTree.bValue == rightSubTree.bValue)
		{
			if (leftSubTree.index < rightSubTree.index)
			{
				answer.aValue = leftSubTree.aValue;
				answer.bValue = leftSubTree.bValue;
				answer.index = leftSubTree.index;
			}else{
				answer.aValue = rightSubTree.aValue;
				answer.bValue = rightSubTree.bValue;
				answer.index = rightSubTree.index;
			}
		}else{
			if(leftSubTree.bValue < rightSubTree.bValue)
			 {
				answer.aValue = leftSubTree.aValue;
				answer.bValue = leftSubTree.bValue;
				answer.index = leftSubTree.index;
			 }else{
				answer.aValue = rightSubTree.aValue;
				answer.bValue = rightSubTree.bValue;
				answer.index = rightSubTree.index;
			 }
		}
	}else{
		if(leftSubTree.aValue > rightSubTree.aValue)
		{
			answer.aValue = leftSubTree.aValue;
			answer.bValue = leftSubTree.bValue;
			answer.index = leftSubTree.index;
		}else{
			answer.aValue = rightSubTree.aValue;
			answer.bValue = rightSubTree.bValue;
			answer.index = rightSubTree.index;
		}
	}
	return answer;
}
int main()
{
	int n;
	cin>>n;
	Worrior *arr=new Worrior[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i].aValue;
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i].bValue;
	}
	Node *tree=new Node[4*n];
	buildSegementTree(arr , tree , 0 , n-1 , 1);
	// for (int i = 0; i < 4*n; ++i)
	// {
	// 	cout<<i<<" "<<tree[i].aValue <<"\t"<<tree[i].bValue<<"\t"<<tree[i].index<<endl;
	// }
	int nQuery;
	cin>>nQuery;
	while(nQuery--)
	{
		int left,right;
		cin>>left>>right;
		Node answer=getAnswer(tree , 0 , n-1 ,  1 , left-1  , right-1);
		cout<<answer.index+1<<endl;//because index start with 0 and required with 1
	}
}