#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int *dp;
vector<int>*edge;
int nWays(int src ){
	int ans=1;
	for(unsigned int i=0 ; i<edge[src].size();i++){
		int adjacent=edge[src][i];
		if(dp[adjacent]!=-1) {
			ans=(ans+dp[adjacent])%mod;
		}else{
		ans=(ans+nWays(adjacent))%mod;
		}
	}
	return dp[src]=ans;
}
int main(){
	int n,m;
	cin>>n>>m;
	edge=new vector<int>[n];
	for(int i=0 ; i<m ; i++){
		int x,y;
		cin>>x>>y;
		edge[x-1].push_back(y-1);
	}
	int src;
	cin>>src;
	dp=new int[n];
		for(int j=0 ; j<n ; j++)	dp[j]=-1;
	int ans=nWays(src-1);
	cout<<ans;
	delete []edge;
	delete []dp;
}