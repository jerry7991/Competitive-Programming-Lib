#include <iostream>
using namespace std;
void update(int index, int value,int * BIT ,int n)
{
	for(;index<n ; index +=(index&(-index)))//index reflects to required position to change
	{
		BIT[index]+=value;
	}
}
int getQuery(int index , int *BIT)
{
	int sum=0;
	for(	;	index>0	;	index-=(index&(-index)))
	{
		sum+=BIT[index];
	}
	return sum;
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n+1];
	int *BIT=new int[n+1]();
	for(int i=1 ; i<=n ; i++)
	{
		cin>>arr[i];
		update(i, arr[i], BIT ,n);
	}
	int nQuery;
	cin>>nQuery;
	while(nQuery--)
	{
		int left,right;
		cin>>left>>right;
		cout<<getQuery(right , BIT)-getQuery(left , BIT)<<endl;
	}
}