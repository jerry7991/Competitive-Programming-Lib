#include <iostream>
using namespace std;
bool helper(int a[] , int b[] , int n, int aStart , int bStart , int minRange , int maxRange)
{
	//travel in array untill find valid node
	int i,k;
	for ( i = aStart; i < n; ++i)
	{
		if(a[i]>minRange && a[i]<maxRange)
			break;
	}
	for(k=bStart ; k<n ; k++)
	{
		if(b[k]>minRange && b[k]<maxRange)
			break;
	}
	//check weather both arr element are at leafe
	if (i==n && k==n)
	{
		return true;
	}
	//if one at leafe other not
	if ((i==n && k!=n) || (i!=n && k==n))
	{
		return false;
	}
	//if current root node element not matching
	if (a[i]!=b[k])
	{
		return false;
	}
	bool leftAns=helper(a,b,n,i+1,k+1,minRange , a[i]);
	bool rightAns=helper(a,b,n,i+1,k+1,a[i],maxRange);
	return (leftAns && rightAns);
}
bool isSameBST(int a[], int b[], int n)
{
	return helper(a,b,n,0,0,INT_MIN , INT_MAX);
}
int main()
{
	int n;
	cin>>n;
	int *arr1=new int[n];
	int *arr2=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr1[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>arr2[i];
	}
	cout<<isSameBST(arr1 , arr2 ,n);
}