#include <iostream>
using namespace std;
class Tries{
public:
	Tries *left,*right;
	int leftCount,rightCount;
	Tries(){
		left=right=NULL;
		leftCount=rightCount=0;
	}
};
void insert(Tries *root , int n){
    if(!root) root=new Tries();
	for(int i=31 ; i>=0 ; i--){
		int currBit=(n>>i)&1;
		if(currBit){
			//one sub arr which is going to add right side so increament right count
			root->rightCount++;
			if(!root->right){
				root->right=new Tries();
			}
			root=root->right;
		}else{
			//one sub arr which is going to add left side so increment left count
			root->leftCount++;
			if(!root->left){
				root->left=new Tries();
			}
			root=root->left;
		}
	}
}
void deleteTries(Tries *root){
	if(!root) return;
	deleteTries(root->left);
	deleteTries(root->right);
	delete root;
}
void solve(){
	int n,k;cin>>n>>k;
	int *arr=new int[n];
	for(int i=0 ; i<n ; i++) cin>>arr[i];
	//process
	Tries *root=new Tries();
	insert(root , 0);
	long long int nSubArr=0, xorTillNow=0;
	for(int i=0 ; i<n ; i++){
		xorTillNow ^=arr[i];
		Tries *temp=root;		
		for(int j=31 ; j>=0  && temp; j--){
			int currBit=(xorTillNow >> j)&1;
			int kBit=(k >> j)&1;
			if(currBit){
				if(kBit){
				//if currBit is set then all the sub array which is at the right side will be less then k cause 1^1 will be 0
					nSubArr+=temp->rightCount;
				//and go for left to more exploration
					temp=temp->left;
				}else{
					//if kBit is unset and currBit is set then we can not go left side because 1^0 will be 0 which will greater
					//than k so more towards right
					temp=temp->right;
				}
			}else{
				if(kBit){
					//if currBit is unset and kBit is set then all subarr at left side will give less than k
					nSubArr+=temp->leftCount;
					//move towards right for further exploration
					temp=temp->right;
				}else{
					//we can not go right side
					temp=temp->left;
				}
			}
		}
		insert(root , xorTillNow);
	}
	cout<<nSubArr<<'\n';
	delete []arr;
	deleteTries(root);
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) solve();
return 0;
}