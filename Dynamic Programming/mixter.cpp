#include <iostream>
#include <vector>
using namespace std;
int sum(int a,int b,vector<int> v)
{
	int sum=0;
	for(int i=a;i<=b;i++)
		sum=(sum+v[i])%100;
	return sum;
}
int helper(vector<int>colors ,int start, int end  ,int **dp)
{
	if (start==end)
	{
		return 0;
	}
	if(dp[start][end]!=-1)
		return dp[start][end];
	int ans=INT_MAX;
	for(int i=start ;i<end ; i++)
	{
		int opt1=helper(colors , start , i,dp)+helper(colors , i+1 , end,dp)+(sum(start,i,colors))*(sum(i+1,end,colors));
		ans=min(ans , opt1);
	}
	dp[start][end]=ans;
	return ans;
}
int solve(int n, vector<int>colors)
{
	int **dp=new int*[colors.size()+1];
	for (int i = 0; i <=colors.size(); ++i)
	{
		dp[i]=new int[colors.size()+1];
		for(int j=0 ; j<=colors.size() ;j++)
			dp[i][j]=-1;
	}
	int ans= helper(colors,0 , colors.size()-1,dp);
	// for (int i = 0; i <=n; ++i)
	// {
	// 	for(int j=0 ; j<=n;j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return ans;
}
int main()
{
	int n;
	cin>>n;
	vector<int>color;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		color.push_back(x);
	}
	cout<<solve(n,color)<<endl;
}