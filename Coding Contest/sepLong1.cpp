#include<bits/stdc++.h>
#define uos unordered_set
using namespace std;
void solve(){
	int n;
	cin>>n;
	int x ,ans=0;
	uos<int> v;
	while(n--){
		cin>>x;
		if(v.find(x)==v.end()){
			ans++;
			v.insert(x);
		}
	}
	cout<<ans<<'\n';
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--) solve();
    return 0;
}