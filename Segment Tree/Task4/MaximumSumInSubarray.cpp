#include<bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
	int totalSum;
	int maxSum;
	int bestPrefixSum;
	int bestSuffixSum;
};
void buildSegementTree(int *arr ,Node* tree , int start,int end , int treeNode)
{
	//base case
	if(start==end)
	{
		tree[treeNode].totalSum=arr[start];
		tree[treeNode].maxSum=arr[start];
		tree[treeNode].bestPrefixSum=arr[start];
		tree[treeNode].bestSuffixSum=arr[start];
		return;
	}
	//other wise we have to travel left subtree and right subtree

	int mid=(start+end)/2;

	//Left subtree:-
	buildSegementTree(arr , tree , start , mid , treeNode*2);

	//right subtree:-
	buildSegementTree(arr , tree , mid+1 , end , treeNode*2+1);

	//while poping the function from stack we are going to build our tree for each treeNode;
	Node leftSubTree	=	tree[treeNode*2];
	Node rightSubTree	=	tree[treeNode*2+1];

	//current node:-
	tree[treeNode].totalSum	=	(leftSubTree).totalSum + (rightSubTree).totalSum;

	//tree[treeNode].maxSum it depend on 3 option;
		//option1 :- we can take any one of left sub tree or right sub tree as our subarray
		int option1 = max(leftSubTree.maxSum , rightSubTree.maxSum);

		/*
			int option2:- we can include all left subtree in subarray and best prefix of right subtree
						  or we can include all right subtree in subarray and best suffix of left subtree
		*/
		int option2 = max( (leftSubTree.totalSum + rightSubTree.bestPrefixSum) , (rightSubTree.totalSum + leftSubTree.bestSuffixSum)); 
		//option3:- we can include partially from left and partialy from right
		int option3 = leftSubTree.bestSuffixSum + rightSubTree.bestPrefixSum;

		int finalAnswer = max(option1 , max(option2 , option3));

	tree[treeNode].maxSum=finalAnswer;
	//best prefixSum
	tree[treeNode].bestPrefixSum = max( (leftSubTree.bestPrefixSum) , (leftSubTree.totalSum + rightSubTree.bestPrefixSum) );
	//best suffixSum
	tree[treeNode].bestSuffixSum = max( (rightSubTree.bestSuffixSum) , (rightSubTree.totalSum + leftSubTree.bestSuffixSum) );
	return;
}
Node getAnswer(Node *tree , int start , int end , int treeNode , int left ,int  right)
{
	//base cases:-
	//their are 3 condition for given particular start and end

	//condition 1:- if start and end are lies completely outside of interval[left,right]
	if(start>right || end <left)
	{
		Node answer;
		answer.totalSum=-1000000;
		answer.maxSum=-1000000;
		answer.bestPrefixSum=-1000000;
		answer.bestSuffixSum=-1000000;
		return answer;
	}
	//condition 2:- If our start and end completely lies in between required interval[left,right]
	if(start >=left && end<=right)
	{
		return tree[treeNode];
	}
	//other wise we have partially interaval so travel in both subtree , right subtree as well as left subtree
	int mid=(start+end)/2;
	//right subtree
	Node answer1=getAnswer(tree , start , mid , treeNode*2 , left , right);
	Node answer2=getAnswer(tree , mid+1 , end , treeNode*2+1  , left , right);

	Node answer;
	answer.totalSum=answer1.totalSum+answer2.totalSum;

	//let's think about answer.maxSum
	//in subArray we have total four option to make an sub array for any particular totalNode
			//option1:- either we can take whole left subtree as a subArray or right subtree as a subArray
			int option1=max(answer1.maxSum , answer2.maxSum);
			/*
			 option2:- A:- Either we can take whole left subtree as a subArray with best right prefix as a sub Array
			 		   B:- Either we can take whole right subtree as a subarray with best suffuxe as a sub array
			*/
				int option2A = answer1.totalSum + answer2.bestPrefixSum;
				int option2B = answer2.totalSum + answer1.bestSuffixSum;
			int option2 = max(option2A , option2B);
			//option 3:- we can include element in subarray from partially left subtree and partially form right subtree 
			int option3 = answer1.bestSuffixSum + answer2.bestPrefixSum;
	answer.maxSum=max(option1 , max(option2 , option3));
	//best prefix;
	answer.bestPrefixSum=max(answer1.bestPrefixSum , answer1.totalSum + answer2.bestPrefixSum);
	//best suffux sum
	answer.bestSuffixSum=max(answer2.bestSuffixSum , answer2.totalSum + answer1.bestSuffixSum);
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
	Node *tree=new Node[4*n];
	buildSegementTree(arr , tree , 0, n-1 , 1);
	int nQuery;
	cin>>nQuery;
	while(nQuery--)
	{
		int left;
		int right;
		cin>>left>>right;
        //left-1 and right-1 due to start indexing from 0
		Node answer=getAnswer(tree , 0 , n-1 , 1 , left-1 , right-1);
		cout<<answer.maxSum<<endl;
	}
	// for (int i = 0; i < 3*n; ++i)
	// {
	// 	cout<<i<<" totalSum "<<tree[i].totalSum << " maxSum "<<tree[i].maxSum <<" bestPrefixSum "<<tree[i].bestPrefixSum << " bestSuffixSum "<<tree[i].bestSuffixSum<<endl;

	// }
}