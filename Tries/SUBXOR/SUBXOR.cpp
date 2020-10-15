#include <iostream>
#include <queue>
using namespace std;
class treisNode{
public:
	treisNode *left;
	int leftLeafeCount;
	treisNode *right;
	int rightLeafeCount;
public:
	treisNode()
	{
		leftLeafeCount=0;
		rightLeafeCount=0;
		left=right=NULL;
	}
};
void deleteTrie(treisNode * head)
{
	if(head!=NULL)
	{
		deleteTrie(head->left);
		deleteTrie(head->right);
		delete head;
	}
}
void buildTries(treisNode *head , int n)
{
	treisNode *currNode=head;
	for(int i=31 ; i>=0 ; i--)
	{
		int bit=(n>>i)&1;
		if (bit==0)
		{
			//increase the number of left leafe count cause one child is going to increase
			currNode->leftLeafeCount++;
			if (!currNode->left)
			{
				currNode->left=new treisNode();
			}
			currNode=currNode->left;
		}else{
			//increase the number of right leafe count cause one right child is going to be added
			currNode->rightLeafeCount++;
			if(!currNode->right)
			{
				currNode->right=new treisNode();
			}
			currNode=currNode->right;
		}
	}
}
int getNSubArrayAsK(int *arr ,int n ,int k)
{
	treisNode *head=new treisNode();
	int nSubArr=0;
	int preXor=0;
	buildTries(head , preXor);
	for (int i = 0; i < n; i++)
	{
		treisNode *currNode=head;
		preXor = arr[i]^preXor;
		int x=k;
		for(int j=31 ; j>=0 ; j--)
		{
			int bitOur=(preXor>>j)&1;
			int bitK=(x>>j)&1;
			if(currNode)
			{
				if(bitK==1)
				{
					//bitk is 1
					if(bitOur==1)
					{
						if(currNode->right)
							nSubArr +=currNode->rightLeafeCount;
						currNode=currNode->left;
					}else{
						if (currNode->left)
							nSubArr +=currNode->leftLeafeCount;
						currNode=currNode->right;
					}
				}else{
					//bits is 0
					if(bitOur==1)
					{
						currNode=currNode->right;
					}else{
						currNode=currNode->left;
					}
				}
			}else{
				break;
			}
		}
		buildTries(head , preXor);
	}
	deleteTrie(head);
	return nSubArr;
}
int main()
{
	int testCase;
	cin>>testCase;
	while(testCase--)
	{
		int n,k;
		cin>>n>>k;
		int *arr=new int[n];
		for(int i=0 ; i<n ; i++)
			cin>>arr[i];
		cout<<getNSubArrayAsK(arr , n , k)<<endl;
		delete[] arr;
	}
}