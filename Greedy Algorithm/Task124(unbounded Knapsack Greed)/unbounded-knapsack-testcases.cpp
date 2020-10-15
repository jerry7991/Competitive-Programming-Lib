#include <bits/stdc++.h>
using namespace std;
int getMaxSum(int *arr ,int n ,int maxWeight)
{
	int answer=0;
int x=maxWeight;
for(int i=0 ; i<n ;i++)
{
    if(maxWeight%arr[i]==0)
    return maxWeight;
    int n=x/arr[i];
    answer += arr[i]*n;
    x -= arr[i]*n;
    if(x<=0)
    return answer;
}
return answer;
}
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n,maxWeight;
		cin>>n>>maxWeight;
		int *arr=new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		cout<<getMaxSum(arr , n , maxWeight)<<endl;
	}
}