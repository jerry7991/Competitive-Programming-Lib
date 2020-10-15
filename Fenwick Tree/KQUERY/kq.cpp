#include <iostream>
using namespace std;
int nMax;
void update(int *BIT , int value)
{
	for(;value<nMax ; value+=(value&(-value)))
	{
		BIT[value]++;
	}
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n+1];
	nMax=0;
	for(int i=1 ; i<=n; i++)
	{
		cin>>arr[i];
		nMax=max(nMax  , arr[i]);
	}
	int *BIT=new int[nMax]();
	for(int i=1;i<=n;i++)
	{
		update(BIT , arr[i]);
	}
	int nQuery;
	cin>>nQuery;
	while(nQuery)
	{
		int left,right,value;
	}
}
