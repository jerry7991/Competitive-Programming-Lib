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







/*

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int sum;
    //char c;
};
int *mod;
long long power(int n)
{
    return mod[n];
}
void buildtree(char *arr,node *tree,int start,int end,int treenode)
{
    if(start==end)
    {
        tree[treenode].sum = arr[start] - '0';
        return;
    }
    int mid =(start+end)/2;
    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);
    tree[treenode].sum = ((power(end-mid)*(tree[2*treenode].sum)%3)%3+tree[2*treenode+1].sum%3)%3;
    
}
void update(char *arr,node *tree,int start,int end,int treenode,int idx)
{
    if(start==end)
    {
        if(arr[start]=='0')
        {
            arr[idx] = '1';
            tree[treenode].sum = 1;
        }
        return;
    }
    int mid =(start+end)/2;
    if(idx>mid)
    {
        update(arr,tree,mid+1,end,2*treenode+1,idx);
    }
    else
    {
        update(arr,tree,start,mid,2*treenode,idx);
    }
    tree[treenode].sum = ((power(end-mid)*(tree[2*treenode].sum)%3)%3+tree[2*treenode+1].sum%3)%3;
}
node query(node *tree,int start,int end,int treeNode,int left,int right)
{
    if(start>right||end<left)
    {
        return {0};
    }
    if(start>=left&& end<=right)
    {
        return tree[treeNode];
    }
    int mid =(start+end)/2;
    if(left>mid)
        return query(tree,start,mid,2*treeNode,left,right);
    else if(right<=mid)
        query(tree,mid+1,end,2*treeNode+1,left,right);
        
    node ans1= query(tree,start,mid,2*treeNode,left,right);
    node ans2= query(tree,mid+1,end,2*treeNode+1,left,right);
    return{((power(end-mid)*(ans1.sum)%3)%3+ans2.sum%3)%3};
}
int main() {
    mod =new int[2*100000];
    mod[0]=1;
    for(int i=1;i<2*100000;i++)
    {
        mod[i]=(mod[i-1]*2)%3;
    }
    int n;
    cin>>n;
    char str[n+1];
    node tree[4*n];
    cin >> str;
    buildtree(str,tree,0,n-1,1);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int j;
        cin>>j;
        if(j==0)
        {
            int left,right;
            cin>>left;
            cin>>right;
            cout<<query(tree,0,n-1,1,left,right).sum<<endl;
        }
        else
        {
            int idx;
            cin>>idx;
            update(str,tree,0,n-1,1,idx);
        }
    }
}*/