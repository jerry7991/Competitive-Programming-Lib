#include<bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& path ,unsigned int i=0 ,unsigned int j=0) {
	 if(path[i][j]) return 0;
	if(i==path.size()-1 && j==path[0].size()-1) return 1;
	path[i][j]=1;
	int ans=0;
	if(i+1<path.size() && !path[i+1][j]){
		ans+=uniquePathsWithObstacles(path , i+1 , j);
	}
	if(j+1<path[0].size() && !path[i][j+1]){
		ans+=uniquePathsWithObstacles(path , i ,j+1);
	}
	path[i][j]=0;
	return ans;
}
int solve(vector<vector<int>> &path){
 unsigned	int n=path.size(),m=path[0].size();
	if(path[0][0] || path[n-1][m-1]) return 0;
	vector<vector<int>> dp(n,vector<int>(m,0));
    bool flag=0;
	for(int i=0 ; i<n && !flag; i++){
        flag=path[i][0];
        dp[i][0]=flag^1;
	}
       flag=0;
	for(int i=0 ; i<m && !flag;i++){
        flag=path[0][i];
        dp[0][i]=flag^1;
	}
	for(int i=1; i<n ; i++){
		for(int j=1; j<m ; j++){
			dp[i][j]=0;
			if(path[i][j]) continue;
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	return dp[n-1][m-1];
}
int main(){
	while(true){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> path(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0 ; j<m ; j++){
		 cin>>path[i][j];
		}
	}
	cout<<solve(path)<<'\n';
  }
 return 0;
}
		