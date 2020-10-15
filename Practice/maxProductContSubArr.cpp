#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {
	int n=nums.size();
	int *pref=new int[n];
	int *suff=new int[n];
	pref[0]=nums[0];
	suff[n-1]=nums[n-1];
	for(int i=1 ; i<n ; i++){
		pref[i]=(pref[i-1]?pref[i-1]:1)*nums[i];
	}
	for(int j=n-2 ; j>=0 ; j--){
		suff[j]=(suff[j+1]?suff[j+1]:1)*nums[j];
	}
	int ans=INT_MIN;
	for(int i=0 ; i<n-1 ; i++){
		ans=max({ans , pref[i]*suff[i+1] , pref[i] , suff[i+1]});
	}
	return ans;
}
int maxProductII(vector<int> &nums){
	int n=nums.size();
	if(n==1) return nums[0];
	int ans=INT_MIN , l=0,r=0;
	for(int i=0 ; i<n; i++){
		l=(l?l:1)*nums[i];
		r=(r?r:1)*nums[n-i-1];
		ans=max({ans , l , r});
	}
	return ans;
}
int main(){
	while(true){
		int n;
		cin>>n;
		if(n==0) return 0;
		vector<int> v;
		for(int i=0 ; i<n ; i++){
			int x;cin>>x;
			v.push_back(x);
		}
		cout<<maxProductII(v)<<'\n';
}
 return 0;
}
		