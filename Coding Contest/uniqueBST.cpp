//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3370/
#include <iostream>
using namespace std;
int numTrees(int n) {
    if(n==0 || n==1) return 1;
    int ans=0;
    for(int i=1 ;i<=n ; i++){
    	ans+=numTrees(i-1)*numTrees(n-i);
    }
    return ans;
}
int numTreesOptimise(){
	int *dp=new int[n+1];
	dp[0]=dp[1]=1;
	for(int i=2; i<=n ; i++){
		dp[i]=0;
		for(int j=1 ; j<=i ; j++){
			dp[i]+=dp[j-1]*dp[i-j];
		}
	}
	int ans=dp[n];
	delete []dp;
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<numTrees(n);
}