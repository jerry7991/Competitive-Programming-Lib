#include<bits/stdc++.h>
using namespace std;
int solve(string s , string t ,int **dp,unsigned int si=0  ,unsigned int ti=0){
	//if t is not ended then no subsequnce found with current instance
	if(si==s.size() && ti!=t.size()) return 0;
	//if t ended ,no matter where is s but we got a subsequence which exactly equal to t
	if(ti==t.size()) return 1;
	//if we have allready a solution for particular instance of si and ti just return them
	if(dp[si][ti]!=-1) return dp[si][ti];
	int ans=0;
	if(s[si]==t[ti]){
		//if curr char equal either we include in our subsequence if we include then have to increase curr for t
		int opt1=solve(s , t,dp,si+1 , ti+1);
		//or we just ignore it then no changes for ti
		int opt2=solve(s , t,dp, si+1 ,ti);
		ans= opt2+opt1;//and store total subsequences
	}else{
		ans= solve(s , t,dp,si+1 ,ti);
	}
	return dp[si][ti]=ans;
}
int numDistinct1(string s , string t){
	int **memo=new int*[s.size()+1];
	for(unsigned int i=0 ; i<s.size()+1 ; i++){
		memo[i]=new int[t.size()+1];
		for(unsigned int j=0;j<t.size()+1 ;j++) memo[i][j]=-1;
	}
	int ans=solve(s , t , memo);
	for(unsigned int i=0  ;i<s.size()+1 ; i++) delete [] memo[i];//release memory
	return ans;
}
int numDistinct2(string s,string t){
	unsigned int sLen=s.size();
	unsigned int tLen=t.size();
	if(tLen==0) return 1;
	int **dp=new int*[sLen+1];
	for (unsigned int i = 0; i < sLen+1; ++i)
	{
		dp[i]=new int[tLen+1];
	}
	//if string t size is 0 then their is always a null solution
	for(unsigned int i=0 ; i<sLen+1 ; i++) dp[i][0]=1;
	for(unsigned int j=0 ; j<tLen+1 ; j++) dp[0][j]=0;
	dp[0][0]=1;
	for(unsigned int i=1 ; i<=sLen ; i++){
		for(unsigned int j=1 ; j<=tLen ; j++){
			dp[i][j]=dp[i-1][j];
			if(s[sLen-i]==t[tLen-j]) dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
		}
	}
	int ans=dp[sLen][tLen];
	for(unsigned int i=0 ; i<=sLen ; i++) delete []dp[i];
	return ans;
}
int numDistinct(string s , string t){
	unsigned int sLen=s.size();
	unsigned int tLen=t.size();
	if(tLen==0) return 1;
	unsigned long long **dp=new unsigned long long*[2];
	for(int i=0  ; i<2 ; i++) dp[i]=new unsigned long long[tLen+1];
	for(unsigned int i=0 ; i<=tLen  ; i++) dp[0][i]=0;
	dp[0][0]=1;
	dp[1][0]=1;
	int flag=1;
	for(unsigned int i=1;i<=sLen ; i++){
		for(unsigned int j=0 ;j<=tLen ; j++){
			dp[flag][j]=dp[flag^1][j];
			if(s[sLen-i]==t[tLen-j]) dp[flag][j]=dp[flag^1][j]+dp[flag^1][j-1];
		}
		flag^=1;
	}
	int ans=dp[flag^1][tLen];
	delete []dp[0];
	delete []dp[1];
	return ans;
}
int main(){
	string s,t;
	cin>>s;
	cin>>t;
	cout<<numDistinct(s,t);
}