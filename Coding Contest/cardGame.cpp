#include<bits/stdc++.h>
using namespace std;
void solve(){
	int Pc , Pr;
	cin>>Pc>>Pr;
	int nPc,nPr;
	nPc=Pc/9+(Pc%9!=0);
	nPr=Pr/9+(Pr%9!=0);
	if(nPc>nPr || nPr==nPc){
		cout<<"1 "<<nPr<<'\n';
	}else{
		cout<<"0 "<<nPc<<'\n';
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