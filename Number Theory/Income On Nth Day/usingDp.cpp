#include <iostream>
#define mod 1000000007
using namespace std;
int nThDayInc(int f0,int f1,int n)
{
	int *dp=new int[n+1];
	dp[0]=f0;
	dp[1]=f1;
	for(long i=2; i <=n ; i++)
    {
        long ans=((long)dp[i-1]+dp[i-2])%mod;
        long mul=(((long)dp[i-1]%mod)*((long)dp[i-2]%mod))%mod;
        long f=(ans+mul)%mod;
        dp[i]=(int)(f%mod);
    }
    for (int i = 0; i <=n; ++i)
    {
    	cout<<dp[i]<<endl;
    }
    int ans=dp[n];
    delete []dp;
	return ans;
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