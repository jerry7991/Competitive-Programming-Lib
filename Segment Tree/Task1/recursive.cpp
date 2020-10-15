#include <iostream>
using namespace std;
int getMin(int *arr  , int n)
{
	int pos=0;
	int swap_count=0;
	for (int i = 1; i <= n; ++i)
	{
		if(arr[i]==i)
			continue;
		for (int j = i; j <= n; ++j)
		{
			if(arr[j]==i)
			{
				pos=j;
				int temp=arr[pos];
				arr[pos]=arr[i];
				arr[i]=temp;
				swap_count +=1;
				break;
			}
		}
	}
	// for (int i = 1; i <= n; ++i)
	// {
	// 	cout<<arr[i]<<"\t";
	// }
	return swap_count;
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for (int i = 1; i <= n; ++i)
	{
		cin>>arr[i];
	}
	cout<<getMin(arr , n);
}