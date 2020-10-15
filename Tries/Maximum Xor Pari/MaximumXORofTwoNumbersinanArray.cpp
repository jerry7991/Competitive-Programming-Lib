#include <iostream>
#include <math.h>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
class triesNode
{
public:
	triesNode * left;
	triesNode * right;	
};
void buildTreis(triesNode * head , int n)
{
	triesNode *curr=head;
	//travers for each bit and 31-th bits will be top of the tree
	for(int i=31 ; i>=0 ; i--)
	{
		//we need to get the 31-th bits
		int bit=(n>>i)&1;
		if(bit==0)
		{
			//we traverse left of tree
			if(!curr->left)
			{
				//i.e. curr->left has null so we have to create a child for this
				curr->left=new triesNode();
			}
			//and traverse the left child
			curr=curr->left;
		}else{
			//i.e. bit is one so we traverse right in traverse
			//check weather curr node has right child or not
			if (!curr->right)
			{
				//if not then make a child on right
				curr->right=new triesNode();
			}
			//traverse to right
			curr=curr->right;
		}
	}
}
int getMaxXor(triesNode * head ,int * array ,int n)
{
	int max_xor=INT_MIN;
	fon(i , n)
	{
		int n=array[i];
		int curr_xor=0;
		triesNode *curr=head;
		for(int j=31 ; j>=0 ; j--)
		{
			int bit=(n>>j)&1;//it will give j-th bits of n
			if(bit==0)
			{
				//if we have bit 0 from n then for getting max xor value we should get one
				//if there is one present then take it
				if (curr->right)
				{
					//we have right child of curr i.e. we have 1;
					//so xor value would be increased
					curr_xor += pow(2,j);
					curr = curr->right;
				}else{
					//we have no option , have to choose 1
					curr = curr->left;
					//left has 0 value that's why it wound increase the xor value
				}
			}else{
				//we have bit of 1 so we should take 0 for which 0^1 give 1 and give max
				//value but before check weather 0 exist or not
				if (curr->left)
				{
					//it increase the xor value
					curr_xor += pow(2, j);
					curr =curr->left;
				}else{
					//we have no option , have to take 1
					curr=curr->right;
					//it doesn't increase curr_xor value cause 1^1=0 and 0*pow(2,j)=0
				}
			}
			//now we have done with current element of array
			max_xor = (curr_xor>max_xor)?curr_xor : max_xor;
		}
	}
	return max_xor;
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
	triesNode *head=new triesNode();
	fon(i , n)
	{
		buildTreis(head , array[i]);
	}
	//now we have successfully inserted all element in treis 
	//now time to find max xor of the element
	int max_xor=getMaxXor(head , array , n);
	cout<<max_xor<<endl;
}