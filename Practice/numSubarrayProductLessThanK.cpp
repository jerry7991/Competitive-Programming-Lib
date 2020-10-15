#include<bits/stdc++.h>
using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	if(k==0) return 0;
	    int left=0 , right=0 , ans=0 , mul=1;
	while(right<nums.size() && left<=right){
	mul *=nums[right];
	while( left<=right && mul>=k ){
		mul/=nums[left];
		left++;
	}
	ans+=(right-left)+1;
	right++;
	}
	return ans;
}
int main(){
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0 ; i<n ; i++) cin>>v[i];
		int k;
	cin>>k;
	cout<<numSubarrayProductLessThanK(v,k)<<'\n';
 return 0;
}
		