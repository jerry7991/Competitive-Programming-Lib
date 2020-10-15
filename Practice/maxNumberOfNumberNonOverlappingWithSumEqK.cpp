#include<bits/stdc++.h>
using namespace std;
int maxNonOverlapping(vector<int>& nums, int target) {
unordered_map<int,int> prefSum;//sum and 
	int n=nums.size();
	int sum=0,ans=0 , rangeTill=-1;
	prefSum[0]=-1;
	for(int i=0 ;i<n ; i++){
		sum+=nums[i];
		//if we have allready a target-sum and which index is graeter than rangeTill now then this would a seq
		if(prefSum.count(sum-target) && prefSum[sum-target]>=rangeTill)
			ans++,rangeTill=i;
		prefSum[sum]=i;
	}
	return ans;
}
int main(){
	int n ,k;
	cin>>n;
	vector<int> v;
	for(int i=0 ; i<n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	cin>>k;
	cout<<maxNonOverlapping(v  , k)<<'\n';
}