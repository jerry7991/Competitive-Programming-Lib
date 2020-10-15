#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define nMax 100000
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define pb(n) push_back(n)
using namespace std;
std::map<char, int> _map;
int BIT[nMax];
bool visited[nMax];
void update(int value , int add )
{
	for(;value<nMax;value +=(value&(-value)))
	{
		BIT[value]+=add;
	}
}
int query(int index)
{
	int sum=0;
	for(;index>0 ; index-=(index&(-index)))
	{
		sum+=BIT[index];
	}
	return sum;
}
int findKthSmallest(int value)
{
	//let's do binary search in BIT
	//and returns lower bound
	int left=0;
	int right=nMax;
	while(left<right)
	{
		int mid=(left+right)/2;
		if(value<=query(mid))
		{
			right=mid;//cause have to return lower bound
		}else{
			left=mid+1;
		}
	}
	return left;
}
int main()
{
	int n;
	cin>>n;
	fon(i,nMax)
	{
		BIT[i]=0;
		visited[i]=false;
	}
	while(n--)
	{
		char opt;int value;
		cin>>opt>>value;
		if (opt=='I')
		{
			if (!visited[value])
			{
				update(value , 1);
			}
		}else if(opt=='D')
		{
			if (visited[value])
			{
				update(value,-1);
				visited[value]=false;
			}
		}else if (opt=='C')
		{
			//to do
			int ans=query(value);
			cout<<ans<<endl;
		}else if (opt=='K')
		{
			
			int ans=findKthSmallest(value);
			cout<<ans<<endl;
		}
	}
}