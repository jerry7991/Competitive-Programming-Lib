#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	long n;
	cin>>n;
	long *arr=new long[n];
	for (long i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sort(arr , arr+n);
	long maxPeri=-1;
	long edg1=-1 , edg2=-1 , edg3=-1;
	for (long i = 2; i < n; ++i)
	{
		if( arr[i-1]+arr[i-2]<=arr[i])
		{
			continue;
		}
		long currPeri= arr[i-1]+arr[i-2]+arr[i];
		if(currPeri>maxPeri)
		{
			maxPeri=currPeri;
			edg1=arr[i-2];
			edg2=arr[i-1];
			edg3=arr[i];
		}else if(currPeri == maxPeri)
		{
			edg1=arr[i-2];
			edg2=arr[i-1];
			edg3=arr[i];
		}
	}
	if(maxPeri!=-1)
	cout<<edg1<<" "<<edg2<<" "<<edg3;
	else
		cout<<-1;
}