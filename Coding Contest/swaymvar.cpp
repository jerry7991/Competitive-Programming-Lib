#include<bits/stdc++.h>
using namespace std;
int n;
int solve(char * s ,char *t , int si=0 , int ti=0 ){
	if(s[si]=='\0' || t[ti]=='\0'){
		return max(n-si , n-ti);
	}
	if(s[si]==t[ti]){
		return solve(s,t,si+1 , ti+1);
	}else{
		int ans1=1+solve(s,t,si+1,ti);
		int ans2=1+solve(s,t,si,ti+1);
		return ans1+ans2;
	}
}
int main(){
	cin>>n;
	char *s=new char[n];
	char *t=new char[n];
	cin>>s;
	cin>>t;
	cout<<solve(s,t);
}