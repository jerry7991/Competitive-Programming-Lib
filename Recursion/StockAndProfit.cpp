#include <iostream>
using namespace std;
int maxProfit(int *arr,int n)
{
	int *prefMin=new int[n];
	int *suffMax=new int[n];
	prefMin[0]=arr[0];
	suffMax[n-1]=arr[1];
	for (int i = 1; i < n; ++i)
	{
		prefMin[i]=min(prefMin[i-1] , arr[i]);
	}
	for(int i=n-1 ; i>=0 ; i--)
	{
		suffMax[i-1]=max(suffMax[i] ,arr[i]);
	}
	int maxProfit=0;
	for (int i = 0; i < n; ++i)
	{
		maxProfit=max(maxProfit , suffMax[i]-prefMin[i]);
		//cout<<i<<" "<<prefMin[i]<<" "<<suffMax[i]<<endl;
	}
	delete []prefMin;
	delete [] suffMax;
	return maxProfit;
}
int main()
{
	int n;
	scanf("%d",&n);
	int *arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",(arr+i));
	}
	printf("%d",maxProfit(arr , n) );
	delete []arr;
}