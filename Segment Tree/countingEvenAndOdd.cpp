#include<bits/stdc++.h>
using namespace std;
class Data{
public:
	int nEven,nOdd;
};
int *arr,n;
Data *tree;
void build(int low ,int high,int iTree){
	if(low==high){
		tree[iTree].nEven=(arr[low]%2==0);
		tree[iTree].nOdd=(arr[low]%2!=0);
		return;
	}
	int mid=(low+high)/2;
	build(low,mid,iTree*2);
	build(mid+1 ,high,iTree*2+1);
	tree[iTree].nEven=tree[iTree*2].nEven+tree[iTree*2+1].nEven;
	tree[iTree].nOdd=tree[iTree*2].nOdd+tree[iTree*2+1].nOdd;
}
void update(int low , int high,int index, int val,int iTree){
	if(low==high){
		arr[index]=val;
		tree[iTree].nEven=(val%2==0);
		tree[iTree].nOdd=(val%2!=0);
		return;
	}
	int mid=(low+high)/2;
	if(index>mid){
		update(mid+1 , high,index,val,iTree*2+1);
	}else{
		update(low ,mid ,index ,val,iTree*2);
	}
	tree[iTree].nEven=tree[iTree*2].nEven+tree[iTree*2+1].nEven;
	tree[iTree].nOdd=tree[iTree*2].nOdd+tree[iTree*2+1].nOdd;
}
Data getAnswer(int low,int high,int lowR , int highR, int iTree){
	if(low>highR || high<lowR || lowR>highR){
		Data ans;
		ans.nOdd=ans.nEven=0;
		return ans;
	}
	if(low>=lowR && high<=highR) return tree[iTree];
	int mid=(low+high)/2;
	if(lowR>mid){
		return getAnswer(mid+1 ,high , lowR ,highR , iTree*2+1);
	}else if(highR<=mid){
		return getAnswer(low , mid , lowR ,highR , iTree*2);
	}
	Data ans,leftAns,rightAns;
	leftAns=getAnswer(low , mid,lowR , highR , iTree*2);
	rightAns=getAnswer(mid+1 , high,lowR , highR , iTree*2+1);
	ans.nEven=leftAns.nEven+rightAns.nEven;
	ans.nOdd=leftAns.nOdd+rightAns.nOdd;
	return ans;
}
int main(){
	cin>>n;
	arr=new int[n];
	tree=new Data[4*n]();
	for(int i=0 ; i<n ; i++) cin>>arr[i];
	build(0,n-1,1);
	int Q;
	cin>>Q;
	while(Q--){
		int ch,x,y;
		cin>>ch>>x>>y;
		if(ch==0){
			update(0,n-1,x-1,y,1);
		}else{
			Data ans=getAnswer(0,n-1,x-1,y-1,1);
			if(ch==1) cout<<ans.nEven<<'\n';
			else cout<<ans.nOdd<<'\n';
		}
	}
}