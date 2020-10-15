#include <iostream>
#define ull unsigned long long
#define mod 1000000007
using namespace std;
void multiply(ull a[2][2] , ull b[2][2])
{
	ull first=((a[0][0]%mod)*(b[0][0]%mod)+(a[0][1]%mod)*(b[0][1]%mod))%mod;
	ull second=((a[0][0]%mod)*(b[0][1]%mod)+(a[0][1]%mod)*(b[1][1]%mod))%mod;
	ull third=((a[1][0]%mod)*(b[0][0]%mod)+(a[1][1]%mod)*(b[0][1]%mod))%mod;
	ull fourth=((a[1][0]%mod)*(b[0][1]%mod)+(a[1][1]%mod)*(b[1][1]%mod))%mod;
	//store back to a
	a[0][0]=first;
	a[0][1]=second;
	a[1][0]=third;
	a[1][1]=fourth;
}
void power(ull m[2][2] , ull n)
{
	if (n==0 || n==1)
	{
		return;
	}
	power(m , n/2);
	//multiply m^n/2 * m^n/2
	multiply(m,m);
	if ((n&1))
	{
		//n is odd then need on more multiplication
		ull a[2][2]={{1,1},{1,0}};
		multiply(m,a);
	}
}
ull fib(ull n)
{
	ull m[2][2]={{1,1},{1,0}};
	power(m,n-1);
	return m[0][0];
}
ull fiboSum(ull m , ull n)
{
	ull mSum,nSum;
	 mSum=fib(m+1);
	 nSum=fib(n+2);
	 return (nSum-mSum+mod)%mod;
}
int main()
{
	ull m,n;
	cin>>m>>n;
	cout<<fiboSum(m,n);
	return 0;
}