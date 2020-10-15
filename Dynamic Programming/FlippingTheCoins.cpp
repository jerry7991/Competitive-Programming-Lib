#include <iostream>
using namespace std;
int solve(int *arr , int n)
{
	int *sum=new int[n+1];
	sum[0]=0;
	int leftRange,rightRange,maxHead=0,modifiedMaxHead;
	//first cal the sum
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+arr[i];

	for( leftRange=1;leftRange<=n ; leftRange++)
	{
		for( rightRange=leftRange ; rightRange <=n;rightRange++)
		{
			//for every slide window get the modified value
			modifiedMaxHead=sum[leftRange-1]+((rightRange-leftRange+1)-(sum[rightRange]-sum[leftRange-1]))+(sum[n]-sum[rightRange-1]);
			if (modifiedMaxHead>maxHead)
			{
				maxHead=modifiedMaxHead;
			}
		}
	}
	return maxHead;
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for (int i = 1; i <=n; ++i)
	{
		cin>>arr[i];
	}
	cout<<solve(arr , n)<<endl;
}