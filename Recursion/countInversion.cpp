#include <iostream>
#define ll long long
using namespace std;
ll getMergeCount(int *arr , int start , int mid ,int end)
{
	int *temp=new int[end-start+1];
	int i=start,j=mid,k=0;
	ll count=0;
	while(i<mid && j<=end)
	{
		if(arr[i]>arr[j])
		{
			count+=(mid-i);
			temp[k++]=arr[j++];
		}else{
			temp[k++]=arr[i++];
		}
	}
	while(i<mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=end)
	{
		temp[k++]=arr[j++];
	}
	for(int i=start , k=0;i<=end ; i++,k++)
	{
		arr[i]=temp[k];
	}
	return count;
}
ll merge(int *arr , int start , int end)
{
	ll ans=0;
	if(start<end)
	{
		int mid=(start+end)/2;
		ll answer1=merge(arr , start , mid);
		ll answer2=merge(arr , mid+1 , end);
		ll answer3=getMergeCount(arr , start , mid+1 , end);
		ans= (answer1+answer2+answer3);
	}
	return ans;
}
ll solve(int *a , int n)
{
	return merge(a , 0 , n-1);
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
	cout<<solve(arr,n)<<endl;
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<arr[i]<<endl;
	// }
	delete[] arr;
	return 0;
}