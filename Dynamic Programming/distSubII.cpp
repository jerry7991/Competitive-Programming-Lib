#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int visited[27];
int getAns(string str , int n , int *dp){
	if(n<0) return 0;
	if(n==0) return 1;
	int &ans=dp[n];
	if(ans!=-1) return ans;
	 ans=(2*getAns(str , n-1 , dp))%mod;
	 //while backtracking we are going to check if n-th char is allready visited or not
	 if(visited[str[n-1]-'A']!=-1){
	 	//ans=(ans-getAns(str, visited[str[n-1]-'A'] , dp)+mod)%mod;
	 	ans=(ans-dp[visited[str[n-1]-'A']]+mod)%mod;
	 }
	 visited[str[n-1]-'A']=n-1;
	 return ans;
}
void solve(){
	for(int i=0 ; i<27 ; i++) visited[i]=-1;
	string str;cin>>str;
	int *dp=new int[str.size()+1];
	for(int i=0 ; i<str.size()+1 ; i++) dp[i]=-1;
	int ans=getAns(str , str.size() , dp);
cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)	 solve();
}