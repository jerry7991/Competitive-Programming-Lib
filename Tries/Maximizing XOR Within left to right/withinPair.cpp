#include <bits/stdc++.h>
using namespace std;
class treisNode
{
public:
	treisNode * left;
	treisNode * right;	
};
void buildTreis(treisNode * head , int n)
{
	treisNode *curr=head;
	for(int i=31 ; i>=0 ; i--)
	{
		//fetch the i-th bits
		int bit=(n>>i)&1;
		if (bit==0)
		{
			//we have to traverse left cause of bit 0
			if (!curr->left)
			{
				//if curr has not left child then 
				curr->left=new treisNode();
			}
			curr=curr->left;
		}else{
			//we have to traverse right cause of bit 1
			if(!curr->right)
			{
				//if curr has not right child
				//then make a right child
				curr->right=new treisNode();
			}
			curr=curr->right;
		}	
	}
}
int getMaxXor(treisNode * head ,int l ,int r)
{
	int max_xor=0;
	for(int i=l ; i<=r ; i++)
	{
		treisNode *curr=head;
		int curr_xor=0;
		for(int j=31; j>=0 ; j--)
		{
			//get the j-th bits
			int bit=(i>>j)&1;
			if (bit==0)
			{
				//if we has 0 then we should take it one
				if (curr->right)
				{
					//take it it'll increase the xor value
					curr_xor += pow(2,j);
					curr=curr->right;
				}else{
					//if we have no 1 then we have no option have to take 0
					curr=curr->left;
				}
			}else{
				//if we has 1 then we should take it zero
				if (curr->left)
				{
					//it will increase the xor value
					curr_xor +=pow(2,j);
					curr = curr->left;
				}else{
					//we have no option we have to take one
					curr = curr->right;
				}
			}
		}
		max_xor =(curr_xor >max_xor)?curr_xor : max_xor;
	}
	return max_xor;
}
int main()
{
	int l,r;
	cin>>l>>r;
	treisNode *head=new treisNode();
	for(int i=l ; i<=r ; i++)
	{
		buildTreis(head , i);
	}
	//we have done with all the element of l to r in our treis
	int max_xor=getMaxXor(head , l ,r);
	cout<<max_xor;
}