#include<bits/stdc++.h>
using namespace std;
int solve( vector<int> &sum ,int **dp, int left , int right ){
	if(left>right) return 0;//invalid interavel
	int &ans=dp[left][right];
	if(ans!=-1) return ans;
	for(int i=left ; i<=right ; i++){
		int leftSum=sum[i]-sum[left-1];//get the left sum and get the right sum
		int rightSum=sum[right]-sum[i];
		if(leftSum>rightSum){
			//left sum will be through out
			ans=max(ans , rightSum+solve(sum, dp ,i+1 ,right));
		}else if(leftSum<rightSum){
			//right sum will be through out
			ans=max(ans , leftSum+solve(sum, dp , left , i));
		}else{
			//let's find both way
			ans=max(ans , max(rightSum+solve(sum ,dp,  i+1 , right) , leftSum+solve(sum ,dp, left , i)));
		}
	}
	return ans;
}
int stoneGameV(vector<int>& stoneValue) {
	int n=stoneValue.size();
	vector<int> sum(n+1);
	int **dp=new int*[n+1];
	sum[0]=0;
	for(int i=0 ; i<=n;i++){
		dp[i]=new int[n+1];
		if(i) sum[i]=sum[i-1]+stoneValue[i-1];
		for(int j=0 ; j<=n ; j++) dp[i][j]=-1;
	}
	return solve(sum,dp ,1 , stoneValue.size());
}
int main(){
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0 ; i<n ; i++) cin>>v[i];
	cout<<stoneGameV(v)<<'\n';
	return 0;
}