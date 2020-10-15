// https://leetcode.com/problems/2-keys-keyboard/
#include <iostream>
#define infinte 1024
using namespace std;
class Solution{
public:
	int minSteps(int n,int copy , int curr,bool flag=false){
		if(curr==n) return 0;
		if(curr>n || copy>n)	return infinte;
		int ans=0;
		if(copy==0){
			ans=1+minSteps(n , curr , curr,true);//true we made a copy
		}else{
			int opt1=infinte;
			int opt2=infinte;
			if(!flag){
				 opt1=1+minSteps(n ,curr , curr,true);//we can copy all the char what i have
			}
			 opt2=1+minSteps(n , copy , curr+copy,false);//we can paste what we have copied lastly
			ans =min(opt1 , opt2);
		}
		return ans;
	}
public:
	int solve(int n , int *dp , int copy=0 , int curr=1,bool flag=false){
		if(curr==n)	return 0;
		if(curr>n || copy>n) return infinte;
		if(dp[curr]!=-1) return dp[curr];
		int ans=0;
		if(copy==0){
			ans=1+solve(n,dp , curr , curr , true);
		}else{
			int opt1=infinte,opt2=infinte;
			if(!flag){
				opt1=1+solve(n , dp , curr , curr , true);
			}
			opt2=1+solve(n,dp,copy , curr+copy , false);
			ans=min(opt1,opt2);
		}
		return dp[curr]=ans;
		///return ans;
	}
public:
	int minSteps1(int n){
		int *dp=new int[n+1];
		for(int i=0 ; i<=n ; i++) dp[i]=-1;
			return solve(n,dp);
	}
};
int main(){
	int n;
	cin>>n;
	Solution *s=new Solution();
	cout<<s->minSteps(n,0,1)<<endl;
	cout<<s->minSteps1(n)<<endl;
}