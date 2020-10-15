#include <iostream>
#include<math.h>
#define fon(i,n) for(int i=0;i<n ; i++)
using namespace std;
class treisNode
{
public:
	treisNode * left;
	treisNode * right;
};
void buildTries(treisNode *head , int element)
{
	treisNode *currNode=head;
	for(int i=31 ; i>=0 ; i--)
	{
		int bit=(element>>i)&1;
		if (bit==0)
		{
			if (!currNode->left)
			{
				currNode->left=new treisNode();
			}
			currNode=currNode->left;
		}else{
			if (!currNode->right)
			{
				currNode->right=new treisNode();
			}
			currNode=currNode->right;
		}
	}
}
int getMaxXor(int * array ,int n)
{
	treisNode *head=new treisNode();
	buildTries(head , array[0]);
	int previous=array[0];
	int maxXor=0;
	for(int i=1;i<n;i++)
	{
		int currMax=0;
		treisNode *currNode=head;
		int element=array[i];
		previous=previous^element;
		for(int j=31;j>=0 ; j--)
		{
			int bit=(previous>>j)&1;
			if(bit==0)
			{
				//for max we should take one side edge if it is
				if(currNode->right)
				{
					//it give the value
					currMax += pow(2,j);
					currNode = currNode->right;
				}else if(currNode->left)
				{	
					//dosen't increase the value
					currNode=currNode->left;
				}
			}else{
				//we have already 1 bit so go to 0 one if it is
				if (currNode->left)
				{
					currMax +=pow(2,j);
					currNode=currNode->left;
				}else if(currNode->right)
				{
					//it dosen't increase the value
					currNode=currNode->right;
				}
			}
		}
		buildTries(head , previous);
		maxXor=(currMax>maxXor)?currMax:maxXor;
	}	
	return maxXor;
}
int main()
{
	int n;
	cin>>n;
	int *array=new int[n];
	fon(i,n)
	{
		cin>>*(array+i);
	}
	cout<<getMaxXor(array , n);
}