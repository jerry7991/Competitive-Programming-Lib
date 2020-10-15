#include <iostream>
#define mod 1000000007
using namespace std;
void multiply(int a[2][2] , int b[2][2])
{
	int first=((a[0][0]%mod)*(b[0][0]%mod)+(a[0][1]%mod)*(b[0][1]%mod))%mod;
	int second=((a[0][0]%mod)*(b[0][1]%mod)+(a[0][1]%mod)*(b[1][1]%mod))%mod;
	int third=((a[1][0]%mod)*(b[0][0]%mod)+(a[1][1]%mod)*(b[0][1]%mod))%mod;
	int fourth=((a[1][0]%mod)*(b[0][1]%mod)+(a[1][1]%mod)*(b[1][1]%mod))%mod;
	a[0][0]=first;
	a[0][1]=second;
	a[1][0]=third;
	a[1][1]=fourth;
}
void power(int a[2][2] , int n)
{
	if (n==0 || n==1)
	{
		return;
	}
	power(a , n/2);
	//multiply a^n/2 * a^n/2
	multiply(a,a);
	if((n&1))
	{
		//i.e. odd
		int m[2][2]={{1,1},{1,0}};
		multiply(a,m);
	}
}
int fib(int n)
{
	int a[2][2]={{1,1},{1,0}};
	power(a,n-1);
	return a[0][0];
}
int modExpo(int a , int c)
{
	int ans=1;
	while(c>0)
	{
		if((c&1))
		{
			long currAns=ans*a;
			ans=(int)(currAns%(mod));
		}
		c/=2;
		a=(a*a)%(mod);
	}
	return ans;
}
int nThDayInc(int a , int b , int n)
{
	int c=fib(n-1);//because we need n-1th fib
	int gN1=modExpo(a,c);cout<<c<<endl;
	int d=fib(n);
	int gN2=modExpo(b,d);cout<<d<<endl;
	int ans=((gN1%mod)*(gN2%mod))%(mod);
	return ans-1;
}
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int f0,f1,n;
		cin>>f0>>f1>>n;
		cout<<nThDayInc(f0,f1,n)<<endl;
	}
}