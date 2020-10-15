#include<bits/stdc++.h>
using namespace std;
int *arr,*tree,*lazy,n;
void build(int low,int high ,int iTree=1){
	if(low==high){
		tree[iTree]=arr[low];
		return;
	}
	int mid=(low+high)/2;
	build(low ,mid,iTree*2);
	build(mid+1,high ,iTree*2+1);
	tree[iTree]=min(tree[iTree*2] ,tree[iTree*2+1]);
}
void update(int left , int right , int val , int low , int high ,int iTree){
	if(low>high) return;
	//process pending operation
	if(lazy[iTree]){
		tree[iTree]+=lazy[iTree];
		if(low!=high){
			lazy[2*iTree]+=lazy[iTree];
			lazy[2*iTree+1]+=lazy[iTree];
		}
		lazy[iTree]=0;
	}
	if(low>right || right<low) return;
	if(low>=left && high<=right){
		tree[iTree]+=val;
		if(left!=right){
			lazy[iTree*2]+=val;
			lazy[iTree*2+1]+=val;
		}
		return;
	}
	int mid=(low+high)/2;
	update(left,right,val,low,mid,iTree*2);
	update(left,right,val,mid+1,high,iTree*2+1);
	tree[iTree]=min(tree[iTree*2] , tree[iTree*2+1]);
}
int getAnswer(int left,int right , int low,int high,int iTree){
	if(left>right) return INT_MAX;
	if(lazy[iTree]){
		tree[iTree]+=lazy[iTree];
		if(low!=high){
			lazy[iTree*2]+=lazy[iTree];
			lazy[iTree*2+1]+=lazy[iTree];
		}
		lazy[iTree]=0;
	}
	if(left>high || right<low) return INT_MAX;
	if(low>=left && high<=right) return tree[iTree];
	int mid=(low+high)/2;
	int leftAns=getAnswer(left , right ,low , mid ,iTree*2);
	int rightAns=getAnswer(left , right ,mid+1 , high ,iTree*2+1);
	return min(leftAns , rightAns);
}
int main(){
	cin>>n;
	arr=new int[n];
	for(int i=0 ; i<n; i++) cin>>arr[i];
	tree=new int[4*n]();
	lazy=new int[4*n]();
	build(0,n-1);
	int nQ;
	cin>>nQ;
	while(nQ--){
		char ch;
		cin>>ch;
		if(ch=='u'){
			int left,right,val;
			cin>>left>>right>>val;
			update(left,right,val,0,n-1,1);
		}else{
			int left,right;
			cin>>left>>right;
			cout<<getAnswer(left,right,0,n-1,1)<<endl;
		}
	}
return 0;
}