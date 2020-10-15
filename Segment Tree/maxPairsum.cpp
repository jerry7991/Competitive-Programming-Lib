#include<bits/stdc++.h>
using namespace std;
struct Pair{
	int Max,sMax;
};
Pair *tree;
int n,*arr;
void build(int st , int en, int iTree){
 if(st==en){
	tree[iTree].Max=arr[st];
	tree[iTree].sMax=INT_MIN;
	return;
 }
 int mid=(st+en)/2;
 build(st,mid,iTree*2);
 build(mid+1 , en,iTree*2+1);
 tree[iTree].Max=max(tree[iTree*2].Max , tree[iTree*2+1].Max);
 tree[iTree].sMax=min(max(tree[iTree*2].Max , tree[iTree*2+1].sMax)	,	max(tree[iTree*2].sMax , tree[iTree*2+1].Max));
}
void update(int idx , int val ,int st , int en , int it){
	if(st==en){
		tree[it].Max=arr[st]=val;
		tree[it].sMax=INT_MIN;
		return;
	}
	int mid=(st+en)/2;
	if(idx>mid){
		update(idx , val , mid+1 ,en , 2*it+1);
	}else{
		update(idx , val , st , mid ,2*it);
	}
 tree[it].Max=max(tree[it*2].Max , tree[it*2+1].Max);
 tree[it].sMax=min(max(tree[it*2].Max , tree[it*2+1].sMax)	,	max(tree[it*2].sMax , tree[it*2+1].Max));
}
Pair getAnswer(int left , int right , int st , int en , int it){
	if(st>right || en<left){
		Pair ans;
		ans.sMax=ans.Max=INT_MIN;
		return ans;
	}
	if(st>=left && en<=right) return tree[it];
	int mid=(st+en)/2;
	Pair leftAns=getAnswer(left , right ,st ,mid,2*it);
	Pair rightAns=getAnswer(left , right , mid+1,en ,2*it+1);
	Pair ans;
	ans.Max=max(leftAns.Max , rightAns.Max);
	ans.sMax=min(max(leftAns.Max , rightAns.sMax) , max(leftAns.sMax , rightAns.Max));
	return ans;
}
int main(){
	int n;
	cin>>n;
	arr=new int[n];
	for(int i=0 ; i<n ; i++) cin>>arr[i];
	tree=new Pair[4*n];
	build(0,n-1,1);
	int q;cin>>q;
	while(q--){
		char ch;
		cin>>ch;
		if(ch=='Q'){
			int left,right;
			cin>>left>>right;
			Pair ans=getAnswer(left-1 ,right-1 ,0 , n-1 ,1);
			cout<<ans.Max+ans.sMax<<'\n';
		}else{
			int idx  ,val;
			cin>>idx>>val;
			update(idx-1,val,0,n-1,1);
		}
	}
return 0;
}