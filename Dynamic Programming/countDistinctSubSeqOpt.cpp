#include <iostream>
#include <string>
#define fon(i,n) for(int i=0 ; i<n ;i++)
#define mod 1000000007 
using namespace std;
void solve()
{
	string str;
	cin>>str;
	int n=str.size();
	int *visitedIndex=new int[27];
	fon(i,27) visitedIndex[i]=-1;
	int *dp=new int[n+1];//it store the number of distinct subsequence
	//base case 
	dp[0]=1;//a null string
	for(int i=1;i<=n;i++)
	{
		long ans=(long)2*dp[i-1];
		dp[i]=ans%mod;//we can attach i-th element with all subsequence till now
		int currChar=str[i-1]-'A';
		if(visitedIndex[currChar]!=-1)
		{
			//that's means this char already visited so have to subtract cause we need distinct
			dp[i]=(dp[i]%mod-dp[visitedIndex[currChar]]%mod+mod)%mod;
		}
		visitedIndex[currChar]=i-1;
	}
    int ans=dp[n];
    delete []dp;
    delete []visitedIndex;
	cout<<ans<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}