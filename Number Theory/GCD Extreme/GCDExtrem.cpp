#include <iostream>
#define nMax 1000001
#define sll signed long long
using namespace std;
sll phi[nMax];
void setEuilerToteint()
{
	for (sll i = 0; i <nMax; ++i)
	{
		phi[i]=i;
	}
	for(sll i=2 ;i<nMax;i++)
	{
		if(phi[i]==i)
		{	
			phi[i]=i-1;
			for(sll j=2;j*i<nMax;j++)
			{
				phi[j*i]=(phi[j*i]*(i-1))/i;
			}
		}
	}
}
sll findG(sll n , sll * result)
{
	for(sll i=1;i<  n;i++)
	{
		for(sll j=2 ; j*i<=n;j++)
			result[i*j]+=(i*phi[j]);
	}
	sll sum=0;
	for (sll i = 1; i <=n; ++i)
	{
		sum+=result[i];
	}
	// for (int i = 1; i <=n; ++i)
	// {
	// 	cout<<result[i]<<endl;
	// }
	return sum;
}
int main()
{
	setEuilerToteint();
	while(1)
	{
		sll n;
		cin>>n;
		if(n==0)	return 0;
		sll *result=new sll[n+1];
		for(sll i=1;i<=n;i++)
		{
			result[i]=0;
		}
		cout<<findG(n , result)<<endl;
		delete []result;
	}
	return 0;
}