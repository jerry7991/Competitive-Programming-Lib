#include<bits/stdc++.h>
using namespace std;
int minDistance(string &word1 , string & word2){
	int n=word1.size(),m=word2.size();
  if(n==0 || m==0) return max(n,m);
	vector<vector<int>>dp(n+1, vector<int>(m+1 ,0));
	//base case
	dp[0][0]=0;
	for(int i=1 ; i<=n ; i++) dp[i][0]=i;
	for(int i=1 ; i<=m ; i++) dp[0][i]=i;
	for(int i=1; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			if(word1[i-1]==word2[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=1+min({dp[i-1][j-1] , dp[i][j-1] ,dp[i-1][j]});
			}
		}
	}
	int ans=dp[n][m];
	return ans;   
}
int minDistanceII(string &word1 , string &word2){
	int n=word1.size() , m=word2.size() , flag=1;
	if(n==0 || m==0) return max(n,m);
	vector<vector<int>> dp(2 , vector<int>(m,0));
	for(int i=0 ; i<2 ; i++) dp[i][0]=i;
	for(int i=0 ; i<=m ; i++) dp[0][i]=i;
		dp[0][0]=(word1[0]!=word2[0]);
	for(int i=1 ; i<=n ; i++){
		for(int j=1; j<=m ; j++){
			dp[flag][j]=dp[flag^1][j-1];
			if(word1[i-1]!=word2[j-1]){
				dp[flag][j]=1+min({dp[flag][j] ,dp[flag^1][j] , dp[flag][j-1]});
			}
		}
		flag^=1;
	}
	return dp[flag^1][m];
}
int main(){
	while(true){
		string word1,word2;
		cin>>word1>>word2;
		if(word1=="x") return 0;
		cout<<minDistanceII(word1 , word2)<<'\n';
	}
 return 0;
}
		