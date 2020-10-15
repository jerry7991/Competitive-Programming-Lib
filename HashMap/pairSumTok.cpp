#include <iostream>
#include <unordered_map>
#include <vector>
#include<algorithm>
#define um unordered_map
using namespace std;
void pairSum(int *input , int size , int x)
{
	um<int , vector<int>> _map;
	for (int i = 0; i <size; ++i)
	{
		vector<int> curr;
		for(int j=0 ; j<size ; j++)
		{
			if (input[i]+input[j]==x)
			{
				curr.push_back(input[j]);
			}
		}
		sort(curr.begin(), curr.end());
		_map[input[i]]=curr;
	}
	um<int , vector<int>>::iterator itr=_map.begin();
	while(itr!=_map.end())
	{
		vector<int> curr=itr->second;
		int p=itr->first;
		for (int i = 0; i < curr.size(); ++i)
		{
			cout<<p<<" "<<curr[i]<<endl;
		}
		itr++;
	}
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
	int k;
	cin>>k;
	pairSum(arr , n , k);
}