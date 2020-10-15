#include <iostream>
#define MOD 1000000007
using namespace std;
void fillPrime(bool *arr , int n)
{
	for(int i=2 ; i*i<=n ; i++)
	{
		if (arr[i])
		{
			for(int j=i*i ; j<=n ; j+=i)
				arr[j]=false;
		}
	}
}
int getNFactDivisor(bool * isPrime ,int n)
{
	int ans=1;
	for (int i = 0; i <=n; ++i)
	{
		if (isPrime[i])
		{
			long currAns=0;
			for(int j=i ; j<=n ;j*=i)
			{
				 currAns+=n/j;
			}
			long temp=ans*(currAns+1);
			ans=(int)(temp%MOD);
		}
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		bool *isPrime=new bool[n+1];
		for (int i = 0; i <=n; ++i)
		{
			isPrime[i]=true;
		}
		//base case 
		isPrime[0]=isPrime[1]=false;
		fillPrime(isPrime , n);
		cout<<getNFactDivisor(isPrime , n)<<endl;
		//return 0;
	}
}