#include <iostream>
#include <unordered_map>
using namespace std;
int highestFrequency(int *arr, int n)
{
	unordered_map<int,int> m;
	for (int i = 0; i < n; ++i)
	{
		m[arr[i]]++;
	}
	int _max=0,value;
	for(int i=0 ;  i<n ; i++)
	{
		if(_max<m[arr[i]])
		{
			value=arr[i];
			_max=m[arr[i]];
		}
	}
	return value;
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n]	;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cout<<highestFrequency(arr,n);
	delete []arr;
}