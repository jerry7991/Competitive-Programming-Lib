#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,*tree,*lazy;
void update(ll low,ll high , ll lowR ,ll highR ,ll val , ll iTree){

	if( lowR>highR) return;
	if(lazy[iTree]){
		tree[iTree]+=(high-low+1)*lazy[iTree];
		if(low!=high){
			lazy[iTree*2]+=lazy[iTree];
			lazy[iTree*2+1]+=lazy[iTree];
		}
		lazy[iTree]=0;
	}
	if(low>highR || high<lowR ) return;
	if(low>=lowR && high<=highR){
		tree[iTree]+=(high-low+1)*val;
		if(low!=high){
			lazy[iTree*2]+=val;
			lazy[iTree*2+1]+=val;
		}
		return;
	}
	ll mid=(low+high)/2;
	update(low , mid , lowR , highR , val , iTree*2);
	update(mid+1 , high , lowR , highR , val , iTree*2+1);
	tree[iTree]=tree[iTree*2]+tree[iTree*2+1];
}
ll getAnswer(ll low , ll high , ll lowR , ll highR ,ll iTree){
	if( lowR>highR) return 0;
	if(lazy[iTree]){
		tree[iTree]+=lazy[iTree]*(high-low+1);
		if(low!=high ){
			lazy[iTree*2]+=lazy[iTree];
			lazy[iTree*2+1]+=lazy[iTree];
		}
		lazy[iTree]=0;
	}
	if(low>highR || high<lowR ) return 0;
	if(low>=lowR && high<=highR) return tree[iTree];
	ll mid=(low+high)/2;
	if(lowR>mid){
		return getAnswer(mid+1 , high , lowR, highR ,iTree*2+1);
	}else if(highR<=mid){
		return getAnswer(low ,mid , lowR , highR , iTree*2);
	}
	ll leftAns=getAnswer(low , mid , lowR ,highR , iTree*2);
	ll rightAns=getAnswer(mid+1 , high , lowR, highR ,iTree*2+1);
	return leftAns+rightAns;
}
void solve(){
	ll q;cin>>n>>q;
	tree=new ll[4*n]();
	lazy=new ll[4*n]();
	while(q--){
		ll choice;cin>>choice;
		if(choice){
			ll lowR , highR;
			cin>>lowR>>highR;
			cout<<getAnswer(0,n-1,lowR-1 ,highR-1 , 1)<<'\n';
		}else{
			ll p,q,v;
			cin>>p>>q>>v;
			update(0,n-1,p-1,q-1,v,1);
		}
	}
	// for(int i=1 ; i<4*n ; i++) cout<<i<<" "<<tree[i]<<'\n';
    delete []tree;
    delete []lazy;
}
int main(){
	int t;cin>>t;
	while(t--) solve();
return 0;
}