#include <iostream>
using namespace std;
int solve(int n ,vector<int>&dp , int turns=1){
	if(n==0) return turns;
	int &ans=dp[n];
	if(ans!=-3) return ans;
	if(turns){
	 for(int i=1; i*i<=n ; i++){
	 	ans=min(ans,solve(n-i*i ,dp , turns^1));
	 }
	}else{
		ans=-2;
		for(int i=1; i*i<=n ; i++){
			ans=max(ans , solve(n-i*i ,dp , turns^1));
		}
	}
	return ans;
}
bool winnerSquareGame(int n) {
vector<int> dp(n+1 , -3);
   if(solve(n ,dp)==0){
   	//means bob loss
   	return true;
   }else{
   	return false;
   }
}
bool optmize(int n){
	bool *dp=new int[n+1];
	for(int i=0 ; i<=n ; i++){
		for(int k=0 ; k*k<=n ; k++){
			if(dp[i-k*k]==false){
				//that means prev player has loss the game i.e. current will wim
				dp[i]=true;
				break;
			}
		}
	}
	return dp[n];
}
int main(){
	int n;cin>>n;
	cout<<winnerSquareGame(n);
	return 0;
}