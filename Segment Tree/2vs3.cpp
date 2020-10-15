#include<bits/stdc++.h>
using namespace std;
int *tree,n,pow2[100000];
char *arr;
void build(int low,int high, int iTree){
	if(low==high){
		tree[iTree]=arr[low]-'0';
		return;
	}
	int mid=(low+high)/2;
	build(low,mid,iTree*2);
	build(mid+1,high,iTree*2+1);
	tree[iTree]=((tree[2*iTree]*pow2[high-mid])%3+tree[iTree*2+1])%3;
}
void update(int low , int high , int index , int iTree){
	if(low==high){
		arr[index]='1';
		tree[iTree]=1;
		return;
	}
	int mid=(low+high)/2;
	if(index>mid){
		update(mid+1,high,index,iTree*2+1);
	}else if(index<=mid){
		update(low ,mid , index , iTree*2);
	}
	tree[iTree]=((tree[iTree*2]*pow2[high-mid])%3+tree[iTree*2+1])%3;
}
int getAnswer(int low , int high , int lowR , int highR ,int iTree){
	if(lowR>highR || low>highR || high<lowR) return 0;
	if(low>=lowR && high<=highR) return tree[iTree];
	int mid=(low+high)/2;
	if(lowR>mid){
		return getAnswer(mid+1 , high , lowR , highR ,iTree*2+1);
	}else if(highR<=mid){
		return getAnswer(low , mid , lowR , highR , iTree*2);
	}
	int leftAns=getAnswer(low , mid , lowR ,highR ,iTree*2);
	int rightAns=getAnswer(mid+1 , high , lowR , highR , iTree*2+1);
	return ((leftAns*pow2[high-mid])%3+rightAns)%3;
}
int main(){
	pow2[0]=1;
	for(int i=1;i<100000;i++) pow2[i]=(pow2[i-1]*2)%3;
	cin>>n;
	arr=new char[n];
	for(int i=0 ; i<n ; i++) cin>>arr[i];
	tree=new int[4*n]();
	build(0,n-1,1);
	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		if(type){
			int index;cin>>index;
			if(arr[index]-'0') continue;
			update(0,n-1,index,1);
		}else{
			int left,right;
			cin>>left>>right;
			cout<<getAnswer(0,n-1,left,right,1)<<'\n';
		}
	}
	// for(int i=1 ; i<4*n ; i++) cout<<i<<" "<<tree[i]<<'\n';
return 0;
}