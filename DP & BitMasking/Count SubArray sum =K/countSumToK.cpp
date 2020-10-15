#include <iostream>
#define fon(i,n) for (int i = 0; i < n; ++i)
using namespace std;
int getAnswer(int *arr , int n , int k)
{
	int  count=0;
	fon(mask , ((1<<n)-1))	//1<<n gives pow(2,n)
	{
		int sum=0;
		fon(j , n)
		{
			//check weather j-th bit set or not in mask
			if ( (mask&(1<<j))!=0)
			{
				//i.e. set so include in sum
				sum +=arr[j];
			}
		}
		if (sum==k)
		{
			count++;
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
		cin>>arr[i];
	}
	int k;
	cin>>k;
	cout<<getAnswer(arr , n , k)<<endl;
}