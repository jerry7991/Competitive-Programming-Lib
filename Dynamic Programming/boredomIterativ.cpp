#include <iostream>
#include <vector>
#define nMax 1001
using namespace std;
int solve(int n , vector<int>in)
{
	int *freq=new int[nMax];
	int *dp=new int[nMax];
	for (int i = 0; i <nMax; ++i)//cause in[i]<=1000;given
	{
		freq[i]=0;
	}
	for(int i=0 ; i<in.size() ; i++)
		freq[in[i]]++;
	dp[0]=0;
	dp[1]=freq[1]*1;
	for(int i=2;i<nMax ; i++)
	{
		dp[i]=max(dp[i-2]+i*freq[i] , dp[i-1]);
	}
	return dp[1000];
}
int main()
{
	int n;
	cin>>n;
	vector<int>in;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		in.push_back(x);
	}
	cout<<solve(n,in);
}