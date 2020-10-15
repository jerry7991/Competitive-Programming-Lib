#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&nums , int x){
	if( x>=nums.size() ) return 0;
	int ans1=nums[x]+solve(nums , x+2 );
	int ans2=solve(nums , x+1 );
	return max(ans1 , ans2);
}
int rob(vector<int>& nums) {
	return solve(nums , 0);
}
int robII(vector<int>&nums){
	if(nums.size()==0) return 0;
	if(nums.size()<1) return nums[0];
	int *dp=new int[nums.size()];
	dp[0]=nums[0];
	dp[1]=max(nums[0] , nums[1]);
	for(int i=2; i<nums.size() ;i++){
		dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
	}
	return dp[nums.size()-1];
}
int main(){
	while(true){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0 ; i<n;i++) cin>>v[i];
			cout<<robII(v)<<'\n';
	}
 return 0;
}
		