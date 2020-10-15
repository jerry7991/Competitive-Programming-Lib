#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
 int mod=1e9+7;
  int ***dp;
  inline int getIndex(vector<int> &nums ,unsigned int len , int val){
	if(len>=nums.size()) return len;
	int st=len , end=nums.size();
	int mid=len , ans=-1;
	while(st<end){
		mid=(st+end)/2;
		if(val>nums[mid]){
      st=mid+1;
    }else if(val==nums[mid]){
      return mid;
    }
    else{
      end=mid;
    }
	}
	return st;
}
  int getAnswer(vector<int>& nums1 , vector<int>& nums2  ,unsigned int len1=0 , unsigned int len2=0 , int currNum=-1){
 if(len2>=nums2.size() || len1>=nums1.size())
	{
		int ans=0;
		while(len1<nums1.size() && currNum==1) dp[len1][len2][currNum]=ans=ans+nums1[len1],len1++;
		while(len2<nums2.size() && currNum==2) dp[len1][len2][currNum]=ans=ans+nums2[len2],len2++;
			return dp[len1][len2][currNum]=ans;
	}
	long int ans=0;
	if(currNum==-1){
		return max(getAnswer(nums1,nums2,0,0,1),getAnswer(nums1,nums2,0,0,2));
	}
    if(dp[len1][len2][currNum]>0) return dp[len1][len2][currNum];
	if(nums1[len1]==nums2[len2]){
		ans=nums1[len1]+max(getAnswer(nums1 , nums2 , len1+1 , len2+1 , 1) , getAnswer(nums1 , nums2 , len1+1 , len2+1 , 2));
	}else if(currNum==1){
			if(len1+1<nums1.size())
			len2=getIndex(nums2 , len2 , nums1[len1+1]);
		ans=nums1[len1]+getAnswer(nums1 , nums2 , len1+1 , len2 , 1);
	}else{
		if(len2+1<nums2.size())
			len1=getIndex(nums1 , len1 , nums2[len2+1]);
		ans=nums2[len2]+getAnswer(nums1 , nums2 , len1 , len2+1 , 2);
	}
	return dp[len1][len2][currNum]=(int)(ans%mod);
  }
   int maxSum(vector<int>& v1, vector<int>& v2 ) {
  dp=new int**[v1.size()+1];
	for(unsigned int i=0 ; i<v1.size()+1 ;i++){
		dp[i]=new int*[v2.size()+1];
		for(unsigned int j=0  ; j<v2.size()+1 ; j++){
			dp[i][j]=new int[3];
			dp[i][j][1]=-1;
			dp[i][j][2]=-1;
		}
	}
	int ans=getAnswer(v1,v2);
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
return 0;
}
/*
22 30
10 15 20 26 35 47 52 61 68 70 73 85 96 100 103 108 116 125 134 143 153 155
6 15 25 36 48 60 71 72 73 83 92 104 113 123 132 141 150 158 169 180 190 199 201 210 219 226 236 245 255 263
*/