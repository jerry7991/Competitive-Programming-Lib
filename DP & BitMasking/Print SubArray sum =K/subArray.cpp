#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int getAnswer(int *arr , int n , int k)
{
	int count=0;
	fon(mask , ((1<<n)-1))
	{
		int sum=0;
		fon(j , n)
		{
			if ((mask&(1<<j))!=0)
			{
				sum +=arr[j];
			}
		}
		if (sum==k)
		{
			count++;
			fon(j ,n)
			{
				if((mask&(1<<j))!=0)
					cout<<arr[j]<<" ";
			}
			cout<<endl;
		}
	}
	return count;
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	fon(i,n)
	{
		cin>>*(arr+i);
	}
	int k;
	cin>>k;
	cout<<getAnswer(arr , n , k);
}
/*
n=8
arr={1 2 3 4 1 2 3 4}
k=6
output=
1 2 3
2 4
2 3 1
1 4 1
1 3 2
4 2
1 2 1 2
3 1 2
1 2 3
3 3
2 1 3
1 2 3
1 2 3
2 4
1 1 4
2 4
16
*/