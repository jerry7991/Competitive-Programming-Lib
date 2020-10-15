#include <bits/stdc++.h>
using namespace std;
int lis(vector<int> &nums){
	int n=nums.size(),res=0 , maxLen=0;
	vector<pair<int,int>>dp(n,{1,1});
	for(int i=0;i<nums.size();i++){
		for(int j=0 ; j<i ; j++){
			if(nums[i]<=nums[j]) continue;
			if (dp[i].first==dp[j].first+1)
			{
				dp[i].second+=dp[j].second;
			}else if (dp[i].first<dp[j].first+1)
			{
				dp[i]={dp[j].first+1 , dp[j].second};
			}
		}
		if(maxLen==dp[i].first) res+=dp[i].second;
		else if(maxLen<dp[i].first){
			maxLen=dp[i].first;
			res=dp[i].second;
		}
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		v.push_back(x);
	}
	cout<<lis(v);
}