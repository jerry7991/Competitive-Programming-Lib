#include <iostream>
using namespace std;
int getMinJump(int *arr , int end , int start)
{
	if (start>=end)
	{
		return 0;
	}
	//cout<<arr[start]<<endl;
	int res=INT_MAX;
	for (int i = 1; i <= arr[start] && i<=end; ++i)
	{
		int ans=1+ getMinJump(arr , end ,start+i );//1 jump counted
		res= (res<ans)? res : ans;
	}
	return res;
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
	cout<<getMinJump(arr , n , 0);
}