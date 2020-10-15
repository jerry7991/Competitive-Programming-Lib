#include <bits/stdc++.h>
using namespace std;
int solve(int n , int *dp){
	if(n==0)	return 0;
	if(n<0) return 100000;
	if(dp[n]!=-1) return dp[n];
	int ans=100000;
	for(int i=1; i*i<=n ; i++){
		ans=min(ans , 1+solve(n-i*i , dp));
	}
	return dp[n]=ans;
}
int numSquares(int n){
	int *dp=new int[n+1];
	for(int i=0 ; i<=n ; i++) dp[i]=-1;
	int ans=solve(n,dp);
	delete []dp;
	return ans;
}
int numSquares1(int n){
	if(n==0 || n==1) return n;
	int *dp=new int[n+1];
	dp[0]=0;
	dp[1]=1;
	// dp[2]=2;
	// dp[3]=3;
	// dp[4]=1;
	for(int i=2 ; i<=n ; i++){
		dp[i]=100000;
		for(int j=1; j*j<=i ; j++){
			dp[i]=min(dp[i] , 1+dp[i-j*j]);
		}
	}
	for(int i=0 ; i<=n ; i++) cout<<dp[i]<<" ";
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	cout<<numSquares1(n);
}