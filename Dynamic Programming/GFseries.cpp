#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll solve(int n , map<int,ll> &found){
	if(n==1 || n==2) return (n==1)?0:1;
	if(found[n]) return found[n];
	ll x=solve(n-2 , found);
	ll y=solve(n-1 , found);
	return found[n]=x*x-y;
}
int main(){
	int t;
	cin>>t;
	while(t--){
	int n;cin>>n;
	if(n==1){
		cout<<0<<'\n';
		continue;
	}
	map<int,ll> found;
	found[1]=0,found[2]=1;
	solve(n , found);
	 for(auto x: found) cout<<(x).second<<' ';
	 cout<<endl;
	}
}