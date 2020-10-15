#include <iostream>
using namespace std;
int solve(int n){
	if(n==0 || n==1) return n;
	int *dp=new int[n+1];
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n ; i++)
	{
		dp[i]=i+dp[i-1];
		if(dp[i]>n) return i-1;
	}
	return -1;
}
int solve1(int n){
	if(n==0 || n==1) return n;
	unsigned int first=0;
	unsigned int second=1;
	unsigned int third=0;
	for(unsigned int i=2; i<=n ;i++){
		third=i+second;
    first=second;second=third;
		if(third>n) return i-1;
	}
	return -1;
}
int solve3(unsigned int n){
 	unsigned int left=0;
 	unsigned int right=n;
 	unsigned int ans=0;
 	while(left<=right){
 		unsigned int mid=left+(right-left)/2;
 		long long sum=((long long)mid*(mid+1))/2;
 		if(sum<=n){
 			ans=mid;
 			left=mid+1;
 		}else{
 			right=mid-1;
 		}
 	}
 	return ans;
}
int main(){
	int n;cin>>n;
	cout<<solve3(n);
}