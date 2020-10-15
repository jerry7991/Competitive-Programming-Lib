#include <iostream>
#include <string>
#define mod 1000000007
using namespace std;
int nWay(string a,string b,string c,int l,int m,int n , int ***dp)
{
	if (n<=0)
	{
		return 1;
	}
    if(l<=0 && m<=0)
    {
        return 0;
    }
	if ( dp[l][m][n]!=-1)
	{
		return dp[l][m][n];
	}
	char curr=c[n-1];
	//let's find curr in both string and recurr with them
	int ans=0;long temp=0;
	for(int i=l-1  ;i>=0;i--)
	{
		if (a[i]==curr)
		{
			temp+=nWay(a,b,c,i,m,n-1,dp);
		}
	}
	for(int i=m-1;i>=0 ; i--)
	{
		if(b[i]==curr)
		{
			temp+=nWay(a,b,c,l,i,n-1,dp);
		}
	}
	ans=(int)(temp%mod);
	dp[l][m][n]=ans;
	return ans;
}
int solve(string a,string b,string c)
{
	int l=a.length(),m=b.length(),n=c.length();
	int ***dp=new int**[51];
	for (int i = 0; i <51; ++i)
	{
		dp[i]=new int*[51];
		for(int j=0 ; j<51 ; j++)
		{
			dp[i][j]=new int[51];
			for(int k=0 ; k<51 ; k++)
				dp[i][j][k]=-1;
		}
	}
	return nWay(a,b,c,l,m,n,dp);
}
int main()
{
	string a,b,c;
	cin>>a>>b>>c;
	cout<<solve(a,b,c);
	return 0;
}