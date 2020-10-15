#include <iostream>
using namespace std;
void solve(){
	int n;
	cin>>n;
	int *dp=new int[n+1];
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	for(int i=3 ; i<=n ; i++){
		dp[i]=dp[i-1] + dp[i-2];
	}
	int ans=dp[n];
	delete []dp;
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}