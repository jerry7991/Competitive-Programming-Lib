#include <iostream>
#include <unordered_map>
#define um unordered_map
using namespace std;
int CountExtraElements(int arr[], int n) 
{
	um<int , int> freq;
	for (int i = 0; i < n; ++i)
	{
		freq[arr[i]]++;
	}
	int count=0;
	um<int,int>::iterator itr=freq.begin();
	while(itr!=freq.end())
	{
		if(itr->second>1)
			count+=((itr->second)-1);
		itr++;
	}
	return count;
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cout<<CountExtraElements(arr , n);
	delete[]arr;
	return 0;
}