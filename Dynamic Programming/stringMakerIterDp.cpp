#include <iostream>
#include <string>
#define mod 1000000007
using namespace std;
int solve(string a,string b,string c)
{
	int l=a.length();
	int m=b.length();
	int n=c.length();
	int ***dp=new int**[l+1];
	for (int i = 0; i <=l; ++i)
	{
		dp[i]=new int*[m+1];
		for(int j=0;j<=m;j++)
		{
			dp[i][j]=new int[n+1];
			for(int k=0 ;k <=n;k++)
				dp[i][j][k]=0;
		}
	}
	for (int i = 0; i <=l; ++i)
	{
		dp[i][0][0]=1;
	}
	for (int i = 0; i <=m; ++i)
	{
		dp[0][i][0]=1;
	}
	dp[0][0][0]=1;
	for(int i=1;i<=l;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if (a[i-1]==c[k-1])
				{
					dp[i][j][k]+=dp[i-1][j][k-1];
				}
				if(b[j-1]==c[k-1])
				{
					dp[i][j][k]+=dp[i][i-1][k-1];
				}
			}
		}
	}
	return dp[l][m][n];
}
int main()
{
	string a;string b;string c;
	cin>>a>>b>>c;
	cout<<solve(a,b,c);
}