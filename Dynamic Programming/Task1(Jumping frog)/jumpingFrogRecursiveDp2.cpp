#include <iostream>
using namespace std;
int getMinJump(int *arr , int len)
{
	int jump=0;
	int *dp=new int[len+1];
	dp[len]=0;
	for(int i=len-1 ; i>=0 ; i--)
	{
		if (arr[i] >= (len-i) )
		{
			dp[i]=len-i;
		}else{
			dp[i]=arr[i];
		}
	}
	for (int i = 0; i <= len; ++i)
	{
		cout<<dp[i]<<" ";
	}
	int start=0;
	while(start<len)
	{
		jump++;
		start += dp[start];
	}
	return jump;
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
	cout<<getMinJump(arr , n-1 );
}