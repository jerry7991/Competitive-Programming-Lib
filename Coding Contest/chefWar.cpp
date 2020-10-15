#include<bits/stdc++.h>
using namespace std;
void solve(){
	int p,h;cin>>h>>p;
	while(h>0 && p>0){
		h-=p;
		p/=2;
	}
	if( p==0 && h>0){
		cout<<0<<endl;
	}else{
		cout<<1<<'\n';
	}
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--) solve();
    return 0;
}