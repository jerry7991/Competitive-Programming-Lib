#include <bits/stdc++.h>
using namespace std;
int *dp;
vector<int>*edge;
int nWays(int src ){
	int ans=0;
	for(int i=0 ; i<edge[src].size() ; i++){
		if(dp[edge[src][i]]!=-1){
			ans=max(ans , 1+dp[edge[src][i]]);
		}else{
		ans=max(ans , 1+nWays(edge[src][i]));
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
/*
my test cases;
5 7
1 2
1 4
1 3
3 4
2 5
2 4
4 5
*/