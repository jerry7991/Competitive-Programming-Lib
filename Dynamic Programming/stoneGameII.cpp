#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &dp ,int m , int ps ,vector<int>&sum){
	if(ps+2*m>=sum.size()-1) return sum[ps];
	int res=0;
	for(int i=1;i<=2*m ;i++){
		int s=sum[pos]-sum[pos+i];
		if(dp[i+pos][max(i,m)]==0){
			dp[i+pos][max(i,m)]=solve(dp , max(i,m) ,i+pos , sum);
		}
		res=max(res ,s+sum[i+pos]-dp[i+pos][max(i,m)] );
	}
	return res;
}
int stoneGameII(vector<int>& piles) {
	vector<vector<int>> dp(piles.size() , vector<int>(piles.size() , 0));
	vector<int> sum(piles.size()+1 ,0);
	for(int i=piles.size()-1 ; i>=0 ; i--) sum[i]=sum[i+1]+piles[i];
	return solve(dp , 1,0,sum);
}
int main(){
	int n;cin>>n;
	vector<int> v;
	for(int i=0 ; i<n ;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	cout<<stoneGameII(v)<<'\n';
}