#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void getLeaf(int *preOrder , int n , vector<int>&leaf)
{
	stack<int>currNode;
	for(int i=0 , j=1;j<n;i++,j++)
	{
		bool found=false;
		if (preOrder[i]>preOrder[j])
		{
			currNode.push(preOrder[i]);
		}else{
			while(currNode.size())
			{
				if (currNode.top()<preOrder[j])
				{
					currNode.pop();
					found=true;
				}else{
					break;
				}
			}
		}
		if(found)
		{
			leaf.push_back(preOrder[i]);
		}
	}
	leaf.push_back(preOrder[n-1]);
}
int main()
{
	int n;
	cin>>n;
	int *preOrder=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>preOrder[i];
	}
	std::vector<int> leaf;
	getLeaf(preOrder,n,leaf);
	for (unsigned int i = 0; i < leaf.size(); ++i)
	{
		cout<<leaf[i]<<" ";
	}
	delete []preOrder;
}
/*
15
8 4 2 1 3 6 5 7 12 10 9 11 14 13 15
*/