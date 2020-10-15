#include <iostream>
using namespace std;
int hasOnlyOneChild(int pre[], int size)
{
	//explanation look notes
	int minRange=INT_MIN , maxRange=INT_MAX,i;
	for ( i = 0; i < size-1; ++i)
	{
		if (pre[i]>maxRange || pre[i]<minRange)
		{
			return 0;
		}
		if (pre[i+1]>=pre[i])
		{
			minRange=pre[i];
		}
		if (pre[i+1]<pre[i])
		{
			maxRange=pre[i];
		}
	}
	if (pre[i]<maxRange && pre[i]>minRange)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int size;
	cin>>size;
	int *arr=new int[size];
	for (int i = 0; i < size; ++i)
	{
		cin>>arr[i];
	}
	cout<<hasOnlyOneChild(arr,size);
}