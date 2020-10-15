#include<bits/stdc++.h>
using namespace std;
// void solve(){
// 	int n,k,x,y;
// 	cin>>n>>k>>x>>y;
// 	if(k==0){
// 		if(x==y) cout<<"YES"<<'\n';
// 		else cout<<"NO"<<'\n';
// 	}else{
// 		x=(x-y+n)%n;
// 		if(x%k==0){
// 			cout<<"YES"<<'\n';
// 		}else{
// 			cout<<"NO"<<'\n';
// 		}
// 	}
// }
void solve(){
	int n,k,x,y;
	cin>>n>>k>>x>>y;
	for(int i=0;i<n;i++){
		x+=k;
		if(x%n==y){
			cout<<"YES"<<'\n';
			return ;
		}
	}
	cout<<"NO"<<endl;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--) solve();
    return 0;
}