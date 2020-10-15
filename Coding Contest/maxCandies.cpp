#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	unsigned long long int grid=n*m;
	unsigned long long int ans;
	int t=min(x,y-1);
	ans=((grid/2)+(grid%2))*t+(grid/2)*max(0,(y-t));
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