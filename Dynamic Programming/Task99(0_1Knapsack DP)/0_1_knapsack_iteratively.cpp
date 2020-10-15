#include <iostream>
using namespace std;
struct Activity
{
	int weight;
	int value;
};
int getMaxValue(Activity * job ,int n , int maxWeight)
{
	int **dp=new int*[n+1];
	for (int i = 0; i <=n; ++i)
	{
		dp[i]=new int[maxWeight+1];
	}
	for (int i = 0; i <=n; ++i)
	{
		dp[i][0]=0;
	}
	for (int i = 0; i <=maxWeight; ++i)
	{
		dp[0][i]=0;
	}
	for (int i = 1; i <=n; ++i)
	{
		for (int j = 0; j <=maxWeight; ++j)
		{
			dp[i][j]=dp[i-1][j];
			if(job[i-1].weight <=j)
			{
				dp[i][j]=max(	dp[i][j] , job[i-1].value+dp[i-1][j-job[i-1].weight]	);
			}
		}
	}
	return dp[n][maxWeight];
}
int main()
{
	int n;
	cin>>n;
	Activity * job=new Activity[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>job[i].weight;
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>job[i].value;
	}
	int maxWeight;
	cin>>maxWeight;

	cout<<getMaxValue(job , n, maxWeight);
}