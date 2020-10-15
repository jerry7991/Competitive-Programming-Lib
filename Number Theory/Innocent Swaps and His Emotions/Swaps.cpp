#include <iostream>
#define mod 1000000007
#define nMax 1000001
#define ull unsigned long long
long fact[nMax];
using namespace std;
int power(long a,long long b)
{
	ull ans=1;
	ull A=a;
	while(b)
	{
		if ((b&1))
		{
			ans=(ans*A)%mod;
		}
		b/=2;
		A=(A*A)%mod;
	}
	return ans%mod;
}
int nWay(int n,int k)
{
	long pOf2=power(2,k);
	long kPart=power(fact[k] , mod-2);
	long nMinusKpart=power(fact[n-k] , mod-2);
	long nPart=fact[n];
	ull ans1=(ull)pOf2*kPart;
	ull ans2=(ull) nMinusKpart*nPart;
	ull ans=((ans1%mod)*(ans2%mod))%mod;
	return ans%mod;
}
int main()
{
	//cout<<power(2,10808080);
	fact[0]=1;
	for (int i = 1; i < nMax; ++i)
	{
		fact[i]=(fact[i-1]*i)%mod;
	}
	int test;
	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		cout<<nWay(n,k)<<endl;
	}
}