#include<bits/stdc++.h>
using namespace std;
#define MAXN 16

long long solve(int like[][MAXN],int n)
{
	int *dp=new int[1<<n];
	for(int i=0 ; i<(1<<n);i++)
	{
		dp[i]=0;
	}
	//travel all mask
	dp[0]=1;
	for(int mask=0 ; mask<((1<<n)-1) ; mask++)
	{
		//check number of set bit
		int nSetBit=0,temp=mask;
		while(temp>0)
		{
			if (temp%2==1)
			{
				nSetBit++;
			}
			temp/=2;
		}
		for (int i = 0; i < n; ++i)
		{
			//we have optio for each person
			//we give chocalte only when person likes it and chocolate not assigned yet
			if (!(mask & (1<<i)) && like[nSetBit][i])
			{
				//we can modify our the way
				dp[mask | (1<<i)] += dp[mask];
			}
		}
	}
	int answer=dp[(1<<n)-1];
	return answer;
}
int main()
{
	int n,like[MAXN][MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			cin>>like[i][j];
		}
	}
	cout<<solve(like,n)<<endl;
}