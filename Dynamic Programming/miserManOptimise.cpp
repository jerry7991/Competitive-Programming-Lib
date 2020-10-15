#include <iostream>
#define fon(i,n) for(int i=1 ; i<=n ; i++)
using namespace std;
int grid[100][100],n,m;
int solve()
{
	int **dp=new int*[n];
	fon(i,n) dp[i]=new int[m];
	//for single bus
	fon(i,n)
		dp[i][1]=grid[i][1];
	//for single city
	fon(i,m)
		dp[1][i]=grid[1][i];
	for(int i=2;i<=n;i++)
	{
		for(int j=1 ; j<=m ; j++)
		{
			if(j==1)
			{
				dp[i][j]=grid[i][j]+min(dp[i-1][j] , dp[i-1][j+1]);
			}else if(j==m)
			{
				dp[i][j]=grid[i][j]+min(dp[i-1][j] , dp[i-1][j-1]);
			}else{
				dp[i][j]=grid[i][j]+min(dp[i-1][j],min(dp[i-1][j-1] , dp[i-1][j+1]));
			}
		}
	}
	int cost=INT_MAX;
	fon(i,m)
		cost=min(cost , dp[n][i]);
	return cost;
}
int main()
{
	cin>>n>>m;
	fon(i,n)
		fon(j,m) cin>>grid[i][j];
	cout<<solve();
}