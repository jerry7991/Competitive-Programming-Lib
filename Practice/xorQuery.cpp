#include<bits/stdc++.h>
using namespace std;
void build(vector<int>&tree,vector<int> &arr , int left,int right,int treeNode){
	if(left==right){
		tree[treeNode]=arr[left];
		return;
	}
	int mid=(left+right)/2;
	build(tree , arr , left , mid, treeNode*2);
	build(tree , arr , mid+1 , right, treeNode*2+1);
	tree[treeNode]=(tree[treeNode*2]^tree[treeNode*2+1]);
}
int getAnswer(vector<int> &tree , int lRange , int rRange , int left , int right , int treeNode){
	if(lRange>rRange || lRange>right || rRange<left) return 0;
	if(left>=lRange && right<=rRange) return tree[treeNode];
	int mid=(left+right)/2;
	if(mid<lRange){
		return getAnswer(tree , lRange , rRange , mid+1,right,treeNode*2+1);
	}else if(mid>=rRange){
		return getAnswer(tree , lRange , rRange , left , mid , treeNode*2);
	}
	int leftAnswer=getAnswer(tree , lRange , rRange , left,mid , treeNode*2);
	int rightAnswer=getAnswer(tree , lRange , rRange , mid+1 ,right , treeNode*2+1);
	return (leftAnswer^rightAnswer);
}
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
	int n=arr.size();
	vector<int> tree(4*n , 0);
	build(tree, arr , 0 ,n-1 , 1);
	vector<int> output;
	for(auto x:queries){
		output.push_back(getAnswer(tree , x[0] , x[1] , 0 , n-1 , 1));
	}
	return output;
}
int main(){
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n ; i++) cin>>arr[i];
	cin>>n;
	vector<vector<int>> q(n,vector<int>(2));
	for(int i=0 ;i<n;i++){
		cin>>q[i][0]>>q[i][1];
	}
	vector<int> output=xorQueries(arr,q);
	for(auto x:output) cout<<x<<' ';
 return 0;
}

/*
class Solution {
    void build(vector<int>&tree,vector<int> &arr , int left,int right,int treeNode){
	if(left==right){
		tree[treeNode]=arr[left];
		return;
	}
	int mid=(left+right)/2;
	build(tree , arr , left , mid, treeNode*2);
	build(tree , arr , mid+1 , right, treeNode*2+1);
	tree[treeNode]=(tree[treeNode*2]^tree[treeNode*2+1]);
}
int getAnswer(vector<int> &tree , int lRange , int rRange , int left , int right , int treeNode){
	if(lRange>rRange || lRange>right || rRange<left) return 0;
	if(left>=lRange && right<=rRange) return tree[treeNode];
	int mid=(left+right)/2;
	if(mid<lRange){
		return getAnswer(tree , lRange , rRange , mid+1,right,treeNode*2+1);
	}else if(mid>=rRange){
		return getAnswer(tree , lRange , rRange , left , mid , treeNode*2);
	}
	int leftAnswer=getAnswer(tree , lRange , rRange , left,mid , treeNode*2);
	int rightAnswer=getAnswer(tree , lRange , rRange , mid+1 ,right , treeNode*2+1);
	return (leftAnswer^rightAnswer);
}
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
	int n=arr.size();
	vector<int> tree(4*n , 0);
	build(tree, arr , 0 ,n-1 , 1);
	vector<int> output;
	for(auto x:queries){
		output.push_back(getAnswer(tree , x[0] , x[1] , 0 , n-1 , 1));
	}
	return output;
    }
};
*/

// class Solution {
// public:
//     vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//     int n=arr.size();
// 	// vector<int> Xor(n+1,0);
//     int *Xor=new int[n+1];
// 	Xor[0]=0;
// 	for(int i=1 ; i<=n ; i++) Xor[i]=Xor[i-1]^arr[i-1];
// 	vector<int> output;
// 	for(auto x:queries) output.push_back(Xor[x[1]+1] ^ Xor[x[0]]);
//     delete []Xor;
// 	return output;
//     }
// };