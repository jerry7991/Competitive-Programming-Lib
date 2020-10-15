#include <iostream>
using namespace std;
// int countWaysToMakeChange(int arr[], int n, int value)
// {
// 	if (n==0 || value<0)
// 	{
// 		return 0;
// 	}
// 	if (value==0)
// 	{
// 		return 1;
// 	}
// 	int opt1=countWaysToMakeChange(arr , n , value-arr[0]);
// 	int opt2=countWaysToMakeChange(arr+1 , n-1,value);
// 	return opt1+opt2;
// }
int countWaysToMakeChange(int arr[]  , int n ,int value)
{
	int **dp=new int*[n+1];
	for (int i = 0; i <=n; ++i)
	{
		dp[i]=new int[value+1];
		for(int j=0 ; j<=value ;j++)
			dp[i][j]=0;
	}
	for(int i=0 ; i<=n ; i++)
	{
		dp[i][0]=1;
	}
	for(int i=0 ; i<=value ; i++)
	{
		dp[0][i]=0;
	}
	dp[0][0]=0;
	for(int i=1; i<=n ; i++)
	{
		for(int j=1 ; j<=value ; j++)
		{
			dp[i][j]=dp[i-1][j];
			if((j-arr[i-1])>=0)
				dp[i][j]+=dp[i][j-arr[i-1]];
		}
	}
	return dp[n][value];
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
	int value;
	cin>>value;
	cout<<countWaysToMakeChange(arr , n, value);
}