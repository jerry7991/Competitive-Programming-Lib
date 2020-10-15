#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr , int target ,vector<int> &dp){
	if(target==0) return 1;
	if(target<0) return 0;
	if(dp[target]!=-1) return dp[target];
	int ans=0;
	for(int i=0 ; i<arr.size() ; i++){
		ans+=solve(arr , target-arr[i] ,dp);
	}
	return dp[target]=ans;
}
int combinationSum4(vector<int>& nums, int target) {
  vector<int> dp(target+1 , -1);
  return solve(nums , target , dp);
}
int combinationSum41(vector<int>&nums , int target){
	vector<unsigned int> dp(target+1);
	dp[0]=1;
	for(int i=1;i<=target ; i++){
		for(auto x: nums){
			if(i>=x) dp[i]+=dp[i-x];
		}
	}
	return dp[target];
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0 ;i<n;i++){
		cin>>v[i];
	}
	int target;cin>>target;
	cout<<combinationSum4(v ,target)<<'\n';
 return 0;
}
		