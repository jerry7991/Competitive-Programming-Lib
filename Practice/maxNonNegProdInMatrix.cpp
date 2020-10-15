#include<bits/stdc++.h>
using namespace std;
int maxProductPath(vector<vector<int>>& grid) {
	int n=grid.size() , m=grid[0].size();
	vector<vector<pair<long,long>>> dp(n,vector<pair<long,long>>(m));
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			if(i==0 && j==0){
				dp[0][0].first=dp[0][0].second=grid[0][0];
				continue;
			}
			auto & up= i>0 ? dp[i-1][j] : dp[i][j-1];
			auto & left= j>0 ? dp[i][j-1] : dp[i-1][j];
			auto first= max(up.first ,left.first) , second=min(up.second , left.second);
			if(grid[i][j]<0){
				swap(first ,second);
			}
			dp[i][j].first=first*grid[i][j];
			dp[i][j].second=second*grid[i][j];
		}
	}
	for(int i=0; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			cout<<"( "<<dp[i][j].first<<" , " <<dp[i][j].second<<")\t";
		}
		cout<<'\n';
	}
	return dp[n-1][m-1].first<0?-1:(dp[n-1][m-1].first)%1000000007;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>grid(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0 ; j<m ; j++) cin>>grid[i][j];
	}
	cout<<maxProductPath(grid)<<'\n';
 return 0;
}
		