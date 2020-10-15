#include <bits/stdc++.h>
#define fon(i,n) for (int i = 0; i < n; ++i)
#define for_n(i,n) for (int i = 1; i <=n; ++i)
#define ll long long
using namespace std;
int main()
{   
	int n,w;
	cin>>n>>w;
	pair<ll , ll>*arr=new pair<ll,ll>[n];
	fon(i,n)
	{
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr , arr+n);
	ll ***dp=new ll**[2];
	fon(i , 2)
	{
		dp[i]=new ll*[n+1];
		fon(j , n+1)
		{
			dp[i][j]=new ll[w+1];
			fon(k , w+1)
			{
				dp[i][j][k]=0;
			}
		}
	}
	int primes[11]={1,2,3,5,7,11,13,17,19,23,29};
	//base case
	for (int i = 1; i <=n; ++i)
	{
		for (int j = 1; j <=w; ++j)
		{
			dp[0][i][j]=dp[0][i-1][j];
			if (j>=arr[i-1].second)
			{
				dp[0][i][j]=max(dp[0][i][j] , dp[0][i-1][j-arr[i-1].second]+arr[i-1].first);
			}
		}
	}
	for_n(prime ,  10)
	{
		int p=prime%2;
		for_n(i,n)
		{
			for_n(j,w)
			{
				dp[p][i][j]=dp[p][i-1][j];
			if(j>=arr[i-1].second)
			 {
				dp[p][i][j]=max(dp[p][i][j] , max((dp[p][i-1][j-arr[i-1].second]+arr[i-1].first) ,(dp[p^1][i-1][j-arr[i-1].second]+arr[i-1].first*primes[prime]) ));
			 }
			}
		}
	}
	cout<<dp[0][n][w]<<endl;
	return 0;
}