#include <iostream>
using namespace std;
int getWaterUnit(int *arr ,int n)
{
	int *left=new int[n];
	int *right=new int[n];
	//base case
	left[0]=arr[0];
	right[n-1]=arr[n-1];
	for (int i = 1; i < n; ++i)
	{
		left[i] = (left[i-1]>arr[i])?left[i-1] : arr[i];
	}
	for(int i=n-2 ; i>=0 ; i--)
	{
		right[i]= (right[i+1]> arr[i]) ? right[i+1] : arr[i];
	}
	int unitWater=0;
	for (int i = 0; i < n; ++i)
	{
		unitWater+=min(left[i] , right[i])-arr[i];
	}
	delete[] left;
	delete[] right;
	return unitWater;
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	fon(i , 0 , n)
	cin>>arr[i];
	int x=getWaterUnit(arr , n);
	cout<<x<<endl;
	delete [] arr;
	return 0;
}