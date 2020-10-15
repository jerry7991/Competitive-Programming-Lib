#include <iostream>
using namespace std;
int getMaxValue(int *weight , int *value , int n, int maxWeight)
{
	int **dp=new int*[2];
	dp[0]=new int[maxWeight+1];
	dp[1]=new int[maxWeight+1];
	//base case;
	for (int i = 0; i <=maxWeight; ++i)
	{
		dp[0][i]=0;
	}
	dp[1][0]=0;
	int flag=1;
	for (int i = 1; i <=n; ++i)
	{
		for (int j=0; j<=maxWeight; ++j)
		{
			dp[flag][j]=dp[flag^1][j];
			if(weight[i-1]<=j)
			{
				dp[flag][j]=max(	dp[flag][j] , value[i-1]+dp[flag^1][j-weight[i-1]]	);
			}
		}
		flag = flag^1;
	}
	int ans= dp[flag^1][maxWeight];
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int *weight=new int[n];
	for (int i = 0; i <n; ++i)
	{
		cin>>weight[i];
	}
	int *value=new int[n];
	for (int i = 0; i <=n; ++i)
	{
		cin>>value[i];
	}
	int maxWeight;
	cin>>maxWeight;
	cout<<getMaxValue(weight , value , n , maxWeight);
	return 0;
}