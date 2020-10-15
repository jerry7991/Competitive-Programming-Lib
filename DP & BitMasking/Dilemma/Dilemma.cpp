#include<bits/stdc++.h>
int find_touches(int pos , int mask , vector<string> &v , int **dp)
{
	//base case
	if ((mask&(mask-1))==0)
	{
		//i.e. only one set bit
		return 0;
	}
	//base case 2
	if (pos<0)
	{
		//we can't do anything
		return 10000;
	}
	//base case 3
	if (dp[pos][mask]!=INT_MAX)
	{
		return dp[pos][mask];
	}
	//calculate
	int touches=0;
	int newmask1=0;
	int newmask2=0;
	for(int i=0;i<v.size();i++)
	{
		if (mask&(1<<i))
		{
			//if set bit, touches increase
			touches++;
			if (v[i][pos]=='0')
			{
				newmask1 |=1<<i;
			}else{
				newmask2 |=1<<i;
			}
		}
	}
	int ans1=find_touches(pos-1 , newmask1 , v , dp)+find_touches(pos-1 , newmask2 , v,dp)+touches;
	int ans2=find_touches(pos-1 , mask , v,dp);
	int ans=(ans1<ans2)?ans1:ans2;
	dp[pos][mask]=ans;
	return ans;
}
int minimumTouchesRequired(int n , vector<string> v)
{
	int **dp=new int*[v[0].size()];
	for(int i=0;i<v[0].size();i++)
	{
		dp[i]=new int[1<<(n+1)];
		for(int j=0;j<(1<<(n+1));j++)
			dp[i][j]=INT_MAX;
	}
	return find_touches(v[0].size()-1 , (1<<n)-1 , v , dp);
}