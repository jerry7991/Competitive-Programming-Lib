#include<bits/stdc++.h>
using namespace std;
int getAnswer(vector<int>& nums1 , vector<int>& nums2 ,int ***dp ,unsigned int len1=0 , unsigned int len2=0 , int currNum=-1){
	if(len2>=nums2.size() || len1>=nums1.size()){
		int ans=0;
		while(len1<nums1.size() && currNum==1) ans+=nums1[len1++];
		while(len2<nums2.size() && currNum==2) ans+=nums2[len2++];
			return ans;
	}
	if(currNum==-1) return max(getAnswer(nums1 , nums2  ,dp, 0 , 0 ,0) , getAnswer(nums1 , nums2  ,dp, 0 , 0 ,1));
	int &ans=dp[len1][len2][currNum];
	if(ans>0) return ans;
	if(nums1[len1]==nums2[len2]){
		ans=nums1[len1]+max(getAnswer(nums1 , nums2 ,dp, len1+1 ,len2+1 , 0) , getAnswer(nums1 , nums2 ,dp, len1+1 ,len2+1 , 1));
	}else if(currNum==0){
		while(len2<nums2.size() && len1+1<nums1.size() && nums2[len2]<nums1[len1+1]) len2++;
		ans=nums1[len1]+getAnswer(nums1 , nums2 , dp , len1+1  , len2 , currNum);
	}else{
		while(len1<nums1.size() && len2+1<nums2.size() && nums1[len1]<nums2[len2+1]) len1++;
		ans=nums2[len2]+getAnswer(nums1 , nums2 , dp ,len1 , len2+1 ,currNum);
	}
	return ans;
}
int maxSum(vector<int> &v1 , vector<int>&v2){
	int ***dp=new int**[v1.size()+1];
	for(unsigned int i=0 ; i<v1.size()+1 ;i++){
		dp[i]=new int*[v2.size()+1];
		for(unsigned int j=0  ; j<v2.size()+1 ; j++){
			dp[i][j]=new int[2];
			dp[i][j][0]=-1;
			dp[i][j][1]=-1;
		}
	}
	int ans=getAnswer(v1,v2,dp);
	return ans;
}
int main(){
	int n , m;
	cin>>n>>m;
	vector<int> v1 ,v2;
	for(int i=0 ; i<n ; i++){
		int x;cin>>x;
		v1.push_back(x);
	}
	for(int i=0 ; i<m ; i++){
		int x;cin>>x;
		v2.push_back(x);
	}
	cout<<maxSum(v1 , v2)<<'\n';
}