#include <bits/stdc++.h>
using namespace std;
int towMod3[1000000];
void buildSegmentTree(char *ch , int *tree , int start , int end ,int treeIndex)
{
	if (start==end)
	{
		tree[treeIndex]=ch[start]-'0';
		return;
	}
	int mid=(start+end)/2;
	//left subtree
	buildSegmentTree(ch , tree , start, mid , treeIndex*2);
	//right subtree
	buildSegmentTree(ch , tree , mid+1 , end , treeIndex*2+1);

	//while poping the function from stack we use to store the tree what i have done
	tree[treeIndex] = ( tree[treeIndex*2+1]	+	( tree[treeIndex*2]*towMod3[end-mid] )%3 )%3;
}
void updateSegmentTree(char *ch ,int* tree , int start , int end , int index ,int treeIndex)
{
	if (start==end)
	{
		if (ch[index]=='0')
		{
			ch[index]='1';
			tree[treeIndex]=1;
            return;
		}
		return;
	}
	int mid=(start+end)/2;
	if (start<= index && index<=mid)
	{
		//need to left travel
        updateSegmentTree(ch , tree , start , mid, index , treeIndex*2);
	}else{
		//need to right travel
		updateSegmentTree(ch , tree , mid+1 , end, index , treeIndex*2+1);
	}
	//while poping the function from stack we are going to save what i have updated
	tree[treeIndex]	=	(tree[treeIndex*2+1]	+	(tree[treeIndex*2]*towMod3[end-mid])%3)%3;
}
int getAnswer(int *tree ,int left , int right , int start,int end ,int treeIndex)
{
	if (left>right || left >end || right<start)
	{
		return 0;
	}
	//complitly inside of given range
	if (left>=start && right <=end)
	{
		return (tree[treeIndex]*towMod3[end-right])%3;
	}
	//partially
	int mid=(left+right)/2;
	int leftAnswer=getAnswer(tree , left , mid , start , end , treeIndex*2);
	int rightAnswer=getAnswer(tree , mid+1 , right , start , end , treeIndex*2+1);
	int answer= (leftAnswer+rightAnswer)%3;
	return answer;
}
int main()
{
	int n;
	cin>>n;
    n++;
	char *ch=new char[n];
	cin>>ch;
	towMod3[0]=1;
	for (int i = 1; i < 1000000; ++i)
	{
		towMod3[i]=(2*towMod3[i-1])%3;
	}
	int *tree=new int[4*n];
	buildSegmentTree(ch , tree , 0 , n-1 , 1);
	int nQuery;
	cin>>nQuery;
	while(nQuery--)
	{
		int choice;
		cin>>choice;
		if (choice==0)
		{
			int start,end;
			cin>>start>>end;
			int answer=getAnswer(tree , 0 , n-1 , start, end ,1);
			cout<<answer<<endl;
		}else{
			int index;
			cin>>index;
            if(ch[index]=='0')
			updateSegmentTree(ch , tree , 0 , n-1 , index , 1);
		}
	}
}