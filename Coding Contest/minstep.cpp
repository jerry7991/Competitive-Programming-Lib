#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	while(n--){
		int x;cin>>x;
		if(x%k){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}