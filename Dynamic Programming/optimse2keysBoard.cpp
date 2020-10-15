#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	bool isPrime[1024];
	int dp[1024];
	void seive(){
		memset(isPrime , false , sizeof(isPrime));
		//chances of prime number is at odd only
		for(int i=3;i<1024;i+=2)	isPrime[i]=true;
		isPrime[2]=true;
		for(int i=3 ; i<1024 ;i+=2){
			if(isPrime[i]){
				for(int j=i*i ; j<1024 ; j+=(2*i))	isPrime[j]=false;
			}
		}
	}
public:
	int solve(int n){
		if(isPrime[n]==true){
			return n;//because on doing copy paste char increase in mulptiple of something...
			//so for n... multiple would be 1*n==n
		}
		if(dp[n]!=-1)	return dp[n];
		int ans=INT_MAX;
		for(int i=2;i*i<=n;i++){
			if((n%i)==0){
				ans=min(ans ,i+solve(n/i));
			}
		}
		return dp[n]=ans;
	}
public:
	int minSteps(int n){
		seive();
		memset(dp , -1 , sizeof(dp));
		dp[1]=0;dp[0]=0;
		return solve(n);
	}
};
int main(){
	int n;
	cin>>n;
	Solution *s=new Solution();
	cout<<s->minSteps(n);
}