#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int *arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sort(arr ,arr+n);
	int big=arr[n-1]-k;
	int small=arr[0]+k;
	if (small >big)
	{
		int temp=big;
		big=small;
		small=temp;
	}
	for (int i = 1; i < n-1; ++i)
	{
		int sub=arr[i]-k;
		int add=arr[i]+k;
		if(sub>=small || add <=big)
			continue;

		if(big-sub <= add-small)
			small=sub;
		else
			add=big;
	}
	cout<<min(arr[n-1]-arr[0] , big-small);
}