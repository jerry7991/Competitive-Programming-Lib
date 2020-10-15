#include <iostream>
using namespace std;
int getMinJump(int *arr , int end , int start , int *dp)
{
	if (start>=end)
	{
		return 0;
	}
	if (dp[start]!=0)
	{
		return dp[start];
	}
	int res=INT_MAX;
	for (int i = 1; i <= arr[start] && i<=end; ++i)//i==1 because we don't want to reach the position which has 0 jump
	{
		int ans=1+ getMinJump(arr , end ,start+i ,dp);//1 jump counted
		res= (res<ans)? res : ans;
	}
	dp[start]=res;
	return res;
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	int *dp=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		dp[i]=0;
	}
	cout<<getMinJump(arr , n , 0 , dp);
}