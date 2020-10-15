#include <iostream>
using namespace std;
int ans(int n , int *dp){
	if(n==1) return 1;
	if(n<1)	return 0;
	if(dp[n]!=-1) return dp[n];
	int opt1=ans(n-1 , dp);
	int opt2=ans(n-2 , dp);
	return dp[n]=(opt1+opt2);
}
void solve(){
	int n;
	cin>>n;
	int *dp=new int[n+1];
	for(int i=0 ; i<=n ; i++) dp[i]=-1;
	cout<<ans(n ,dp)<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}