#include <iostream>
using namespace std;
void retotate(int *arr , int start , int end)
{
	int x=arr[end];
	for (int i = end; i >start; --i)
	{
		arr[i]=arr[i-1];
	}
	arr[start]=x;
}
void rearrange(int n ,int *arr)
{
	for (int i = 0; i < n; ++i)
	{
		if((i%2)==0)
		{
			if(arr[i]>0)
				continue;
			int x=i+1;
			while(1 && x<n)
			{
				if(x%2==0)
				{
					if(arr[x]<0)
						break;
				}else{
					if(arr[x]>0)
						break;
				}
				x++;
			}
				retotate(arr , i ,x-1);
		}else{
			if (arr[i]<0)
			{
				continue;
			}
			int x=i+1;
			while(1 && x<n)
			{
				if(x%2==0)
				{
					if(arr[x]<0)
						break;
				}else{
					if(arr[x]>0)
						break;
				}
				x++;
			}
			
			retotate(arr , i ,x-1);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
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
	rearrange(n , arr);
	delete []arr;
	return 0;
}