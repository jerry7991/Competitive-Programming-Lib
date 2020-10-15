#include <iostream>
#define fon(i, k, n) for(int i=k ; i<n ; i++)
using namespace std;
int getWaterUnit(int *arr , int n)
{
	int totalUnit=0;
	for(int i=1;i<n-1;i++)
	{
		//find max element in left 
		int left=arr[i];
		for(int j=0;j<i;j++)
		{
			left=(left>arr[j])?left:arr[j];
		}
		//find max on right side
		int right=arr[i];
		for(int j=i+1 ;j<n ; j++)
		{
			right=(right>arr[j])?right:arr[j];
		}
		//which has min height that unit will be added for current particular i-th piller
		totalUnit +=	min(left,right) - arr[i];
	}
	return totalUnit;
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