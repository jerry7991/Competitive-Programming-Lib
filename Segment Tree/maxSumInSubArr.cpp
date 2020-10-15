#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	int sum,bPS,bSS,maxSum;
};
Node *tree;
int *arr;
int n;
inline Node getAns(Node left , Node right){
	Node ans;
	ans.sum=left.sum+right.sum;
	ans.maxSum=max({max(left.maxSum , right.maxSum) ,max(left.sum+right.bPS , right.sum+left.bSS) , left.bSS+right.bPS});
	ans.bPS=max(left.sum+right.bPS ,left.bPS);
	ans.bSS=max(right.sum+left.bSS , right.bSS);
	return ans;
}
void build(int st,int en , int it){
	if(st==en){
		Node cur;
		cur.sum=arr[st];
		cur.bPS=cur.bSS=cur.maxSum=arr[st];
		tree[it]=cur;
		return;
	}
	int mid=(st+en)/2;
	build(st,mid , it*2);
	build(mid+1,en,it*2+1);
	tree[it]=getAns(tree[it*2] , tree[it*2+1]);
}
Node query(int left , int right , int st , int en ,int it){
	if(st>right || en<left){
		Node ans;
		ans.maxSum=ans.bSS=ans.bPS=ans.sum=-1000000;
		return ans;
	}
	if(st>=left && en<=right) return tree[it];
	int mid=(st+en)/2;
	Node leftAns=query(left , right  , st ,mid ,it*2);
	Node rightAns=query(left , right , mid+1 ,en , it*2+1);
	Node ans=getAns(leftAns  , rightAns);
	return ans;
}
int main(){
	cin>>n;
	arr=new int[n];
	tree=new Node[4*n];
	for(int i=0 ; i<n ; i++) cin>>arr[i];
	build(0,n-1,1);
// for(int i=0 ; i<4*n ; i++) cout<<i<<" "<<tree[i].sum<<" "<<tree[i].maxSum<<" "<<tree[i].bSS<<" "<<tree[i].bPS<<'\n';
	int q;
	cin>>q;
	while(q--){
		int left,right;
		cin>>left>>right;
		cout<<query(left-1,right-1,0,n-1,1).maxSum<<endl;
	}
}