#include <iostream>
#define nMax 1000001
#define sll signed long long
using namespace std;
sll phi[nMax];
sll output[nMax];
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
void findG(sll n=nMax)
{
	for(sll i=1;i<  n;i++)
	{
		for(sll j=2 ; j*i<=n;j++)
			output[i*j]+=(i*phi[j]);
	}
	for (sll i = 2; i <=n; ++i)
	{
		output[i]+=output[i-1];
	}
}
int main()
{
	setEuilerToteint();
	for (int i = 1; i < nMax; ++i)
	{
		output[i]=0;
	}
	findG();
	while(1)
	{
		sll n;
		cin>>n;
		if(n==0)	return 0;
		cout<<output[n]<<endl;
	}
	return 0;
}