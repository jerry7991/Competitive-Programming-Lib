#include<bits/stdc++.h>
using namespace std;
class Warrior{
public:
	int a,b,i;
	Warrior(){
		a=b=i=-1;
	}
};
int n;
Warrior *warrior;
Warrior *tree;
Warrior getWorrior(Warrior w1 , Warrior w2){
	Warrior ans;
	if(w1.a==w2.a){
		if(w1.b==w2.b){
			if(w1.i<w2.i){
				return ans=w1;
			}else{
				return ans=w2;
			}
		}else if(w1.b<w2.b){
			return ans=w1;
		}else {
			return ans=w2;
		}
	}else if(w1.a>w2.a){
		return ans=w1;
	}else{
		return ans=w2;
	}
}
void buildTree(int low,int high,int iTree){
	if(low==high){
		tree[iTree].i=warrior[low].i;
		tree[iTree].a=warrior[low].a;
		tree[iTree].b=warrior[low].b;
		return;
	}
	int mid=(low+high)/2;
	buildTree(low,mid,iTree*2);
	buildTree(mid+1,high,iTree*2+1);
	tree[iTree]=getWorrior(tree[iTree*2] , tree[iTree*2+1]);
}
Warrior getQuery(int low,int high ,int lowR , int highR , int iTree){
	if(lowR>highR || low>highR || high<lowR){
		Warrior ans;
		ans.i=ans.b=INT_MAX;
		ans.a=INT_MIN;
		return ans;
	}
	if(low>=lowR && high<=highR) return tree[iTree];
	int mid=(low+high)/2;
	if(lowR>mid){
		return getQuery(mid+1,high , lowR , highR , iTree*2+1);
	}else if(highR<=mid){
		return getQuery(low , mid , lowR,highR,iTree*2);
	}
	Warrior leftAns,rightAns;
	leftAns=getQuery(low , mid , lowR, highR,iTree*2);
	rightAns=getQuery(mid+1,high , lowR , highR , iTree*2+1);
	return getWorrior(leftAns , rightAns);
}
int main(){
	cin>>n;
	warrior=new Warrior[n];
	tree=new Warrior[4*n];
	for(int i=0 ; i<n ; i++){
		warrior[i].i=i;
		cin>>warrior[i].a;
	}
	for(int i=0 ; i<n ; i++){
		cin>>warrior[i].b;
	}
	buildTree(0,n-1,1);
	// for(int i=1;i<4*n;i++) cout<<i<<" -> "<<tree[i].a<<" "<<tree[i].b<<" "<<tree[i].i<<'\n';
	int q;
	cin>>q;
	while(q--){
		int left,right;
		cin>>left>>right;
		cout<<getQuery(0,n-1,left-1,right-1,1).i+1<<'\n';
	}
}	