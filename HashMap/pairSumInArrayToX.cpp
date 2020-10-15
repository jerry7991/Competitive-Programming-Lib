#include <iostream>
#include <unordered_map>
#define um unordered_map
using namespace std;
void pairSum(int input[], int size, int x) 
{
	um<int,int> _map;
	for (int i = 0; i < size; ++i)
	{
		_map[input[i]]++;
	}
	for (int i = 0; i < size; ++i)
	{
		int sum=x-input[i];
		if(_map[sum])
		{
			int x,y;
			x=(sum<input[i])?sum:input[i];
			y=(sum>input[i])?sum:input[i];
			int n=_map[sum];
			while(n--)
			{
				cout<<x<<" "<<y<<endl;
			}
			_map[input[i]]--;
		}
	}
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
	int x;
	cin>>x;
	pairSum(arr , n,x);
}