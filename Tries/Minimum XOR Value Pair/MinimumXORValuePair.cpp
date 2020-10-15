#include <bits/stdc++.h>
using namespace std;
class treisNode
{
public:
	treisNode * left;
	treisNode * right;	
};
void buildTreis(int n , treisNode * head)
{
	treisNode *curr=head;
	for(int i=31 ; i>=0 ; i--)
	{
		int bit=(n>>i)&1;
		if (bit==0)
		{
			//have to traverse in left
			if (!curr->left)
			{
				//if curr has no left child  then make left child
				curr->left=new treisNode();
			}
			curr = curr->left;
		}else{
			//have to traverse in right cause of 1 bit
			if (!curr->right)
			{
				//if curr has no right child then make it
				curr->right=new treisNode( );
			}
			curr=curr->right;
		}
	}
}
int getMinXor(int *array  ,int n ,treisNode * head)
{
	int min_xor=INT_MAX;
	for (int i = 1; i < n; ++i)
	{
		treisNode * curr=head;
		int curr_min=0;
		int n=array[i];
		for(int j=31 ; j>=0 ; j--)
		{
			int bit=(n>>j)&1;
			if(bit==0)
			{
				//for min we have to take 0
				if (curr->left)
				{
					curr=curr->left;
				}else if(curr->right){
					curr_min += pow(2,j);
					curr=curr->right;
				}
			}else{
				//for min we have to take 1
				if (curr->right)
				{
					curr = curr->right;
				}else if(curr->left){
					curr_min += pow(2,j);
					curr=curr->left;
				}
			}
		}
		buildTreis(array[i] , head);
		min_xor = ((curr_min)<min_xor)?(curr_min) :min_xor;
	}
	return min_xor;
}
int main()
{
	int n;
	cin>>n;
	int *array=new int[n];
	treisNode * head=new treisNode();
	for(int i=0 ; i<n ; i++)
	{
		cin>>*(array+i);
	}
		buildTreis(array[0] , head);
	int min_xor=getMinXor(array  , n , head);
	cout<<min_xor;
}