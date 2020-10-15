#include<bits/stdc++.h>
using namespace std;
class NumArray {
private:
	 vector<int>* nums;
	int *tree;
public:
    NumArray(vector<int>& num) {
    	nums=&num;
    	 if(num.size()){
    	tree=new int[4*num.size()];
    	buildTree(0 , num.size()-1 ,1);
      }
    }
    void  buildTree(int start , int end ,int treeNode){
    	if(start==end){
    		tree[treeNode]=nums->at(start);
    		return ;
    	}
    	int mid=(start+end)/2;
    	buildTree(start , mid , treeNode*2);
    	buildTree(mid+1 , end , treeNode*2+1);
    	tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];
    }
    void update(int i, int val) {
    	processUpdate(i,val ,0, nums->size()-1 ,1);
    }
    void processUpdate(int idx , int val , int start ,int end ,int treeNode){
    	if(start==end){
    		(*nums)[idx]=val;
    		tree[treeNode]=val;
    		return;
    	}
    	int mid=(start+end)/2;
    	if(mid<idx){
    		processUpdate(idx , val , mid+1 , end , treeNode*2+1);
    	}else{
    		processUpdate(idx , val  , start ,mid , treeNode*2);
    	}
    	tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];
    }
    int sumRange(int i, int j ) {
    	return processSumRange(i,j,0,nums->size()-1 ,1);
    }
    int processSumRange(int left , int right , int start , int end  , int treeNode){
    	if(start>right || end<left) return 0;
    	if(start>=left && end<=right) return tree[treeNode];
    	int mid=(start+end)/2;
    	int leftSum=processSumRange(left , right , start ,mid , treeNode*2);
    	int rightSum=processSumRange(left , right , mid+1 ,end ,treeNode*2+1);
    	return (leftSum+rightSum);
    }
};
int main(){
	int n;
	cin>>n;
	vector<int> v;
	while(n--){
		int x;cin>>x;
		v.push_back(x);
	}
	NumArray *obj=new NumArray(v);
	int nQuery;
	cin>>nQuery;
	while(nQuery--){
		int choice;
		cin>>choice;
		if (choice)
		{
			int i,val;
			cin>>i>>val;
			obj->update(i,val);
		}else{
			int left,right;
			cin>>left>>right;
			int ans=obj->sumRange(left,right);
			cout<<ans<<'\n';
		}
	}
}