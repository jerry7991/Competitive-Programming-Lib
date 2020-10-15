#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int **matrix=new int*[n];
	for (int i = 1; i <=n; ++i)
	{
		matrix[i]=new int[m];
		for (int j = 1; j <=m; ++j)
		{
			cin>>matrix[i][j];
		}
	}
	int **dp=new int*[n];
	for (int i = 1; i <=n; ++i)
	{
		dp[i]=new int[m];
	}
	//base case for row
	//if 1 cities will present then bus cost will be for m-th bus matrix[1][m]
	for (int i = 1; i <=m; ++i)
	{
		dp[1][i]=matrix[1][i];
	}
	//if 1 bus present then city cost will be city distance
	for (int i = 1; i <=n; ++i)
	{
		dp[i][1]=matrix[i][1];
	}
	for (int i = 2; i <=n; ++i)
	{
		for (int j = 1; j <=m; ++j)
		{
            if(j==1)
            {
                dp[i][j]= matrix[i][j] + min(	dp[i-1][j]	,dp[i-1][j+1])	;  
            }else if(j==m)
            {
                dp[i][j]= matrix[i][j] + min(	dp[i-1][j-1] ,dp[i-1][j]	);   
            }else{
             dp[i][j]= matrix[i][j] + min(	dp[i-1][j-1] ,min(	dp[i-1][j]	,dp[i-1][j+1])	);     
            }
		}
	}
	int minCost=INT_MAX;
	for (int i = 1; i <=m; ++i)
	{
			minCost=min(minCost, dp[n][i] );
	}for (int i = 1; i <=n; ++i)
	{
		delete [] dp[i];
		delete [] matrix[i];
	}
	delete [] dp;
	delete [] matrix;
	cout<<minCost;
    return 0;
}