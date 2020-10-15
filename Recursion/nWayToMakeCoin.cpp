#include <iostream>
using namespace std;
int countWaysToMakeChange(int *arr , int n , int total )
{
	if(total<0 || n==0)
		return 0;
	if (total==0)
	{
		return 1;
	}
	int ans1=countWaysToMakeChange(arr , n ,total-arr[0]  );
	int ans2=countWaysToMakeChange(arr+1 , n-1 , total );
	return (ans1+ans2);
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
	int total;
	cin>>total;
	cout<<countWaysToMakeChange(arr , n , total);
}