#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int *incrSubS=new int[n];
	incrSubS[0]=1;
	for (int i = 1; i < n; ++i)
	{
		incrSubS[i]=1;
		for (int j=i-1 ; j>=0 ; j--)
		{
			if(arr[j]<arr[i])
			{
				incrSubS[i]++;
			}
		}
	}
	// if(arr[i]>arr[i-1])
	// 	{
	// 		incrSubS[i] =incrSubS[i-1]+1;
	// 	}else{
	// 		incrSubS[i]=1;
	// 	}
	int x=0,y;
	for (int i = 0; i < n; ++i)
	{
		if(x<incrSubS[i])
		{
			x=incrSubS[i];
			y=i;
		}
	}
	x++;
	for (int i = y+1; i <n; ++i)
	{
		if(incrSubS[i+1]<incrSubS[i])
		{
			break;
		}x++;
	}
	cout<<x;
}