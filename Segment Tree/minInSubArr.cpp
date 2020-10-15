#include<bits/stdc++.h>
using namespace std;
inline int min(int a,int b) {
	return (a>b)?b:a;
}
int n,*arr,*tree;
void build(int st ,int end , int iTree){
	if(st==end){
		tree[iTree]=arr[st];
		return;
	}
	int mid=(st+end)/2;
	build(st,mid,iTree*2);
	build(mid+1 , end ,iTree*2+1);
	tree[iTree]=min(tree[iTree*2],tree[iTree*2+1]);
}
void update(int i,int val, int st , int end , int iTree=1){
	if(st==end){
		tree[iTree]=arr[i]=val;
		return;
	}
	int mid=(st+end)/2;
	if(i<=mid){
		update(i,val,st,mid,iTree*2);
	}else{
	update(i,val, mid+1 ,end,iTree*2+1);
	}
	tree[iTree]=min(tree[iTree*2],tree[iTree*2+1]);
}
int getAns(int left , int right , int st,int end ,int iTree=1){
	if(st>right ||  end<left) return INT_MAX;
	if(st>=left && end<=right) return tree[iTree];
	int mid=(st+end)/2;
	int leftAns=getAns(left , right , st , mid ,iTree*2);
	int rightAns=getAns(left , right , mid+1 ,end,iTree*2+1);
	return min(leftAns , rightAns);
}
int main(){
	int q;
	cin>>n>>q;
	arr=new int[n];
	tree=new int[4*n];
	for(int i=0 ; i<n ; i++)scanf("%d",(arr+i));
	build(0,n-1,1);
	for(int i=0  ; i<4*n ; i++) printf("%d ",tree[i] );
	while(q--){
		char ch;
		scanf("%c",&ch);
		if(ch=='q'){
			int left,right;
			scanf("%d",&left);
			scanf("%d",&right);
			int ans=getAns(left , right,0,n-1);
			printf("%d\n",ans);
		}else{
			int i,value;
			scanf("%d",&i);
			scanf("%d",&value);
			update(i,value,0,n-1);
		}
	}
}