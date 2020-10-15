#include <iostream>
using namespace std;
int solve(int arr[],int n)
{
	int leftRange=0,rightRange=0,pivot=0,currMax=0;
	while(rightRange<n)
	{
		leftRange=pivot;
		rightRange=pivot;
		while(rightRange<n-1 && arr[rightRange]<arr[rightRange+1])
			rightRange++;
		//one more chance
		rightRange++;
		pivot=rightRange;
		while(rightRange<n-1 && arr[rightRange]<arr[rightRange+1])
			rightRange++;
		int curr=(rightRange-leftRange+1);
		if (currMax<curr)
		{
			currMax=curr;
		}
	}
	return currMax;
}
int main()
{
	int n;
	cin>>n;
	int*arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cout<<solve(arr , n);
}