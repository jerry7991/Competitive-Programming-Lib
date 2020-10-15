#include<bits/stdc++.h>
using namespace std;
class Tries{
public:
	Tries *left , *right;
};
void insert(Tries *root , int number){
	for(int i=31  ; i>=0 ; i--){
		int currBit=(number>>i)&1;
		if(currBit){
			if(!root->right){
				root->right=new Tries();
			}
			root=root->right;
		}else{
			if(!root->left){
				root->left=new Tries();
			}
			root=root->left;
		}
	}
}
int maxXorSubArr(int *arr , int n){
	if(n==0) return 0;
	if(n==1) return 1;
	Tries *root=new Tries();
	insert(root,arr[0]);
	int currXor=0 , xorTillNow=arr[0] , maxXor=arr[0];
	for(int i=1 ; i<n ; i++){
	Tries *temp=root;
		xorTillNow ^=arr[i];
		currXor=0;
		for(int j=31 ; j>=0 ; j--){
			int currBit=(xorTillNow>>j)&1;
			if(currBit){
				if(temp->left){
					currXor+=(1<<j);
					temp=temp->left;
				}else if(temp->right){
					temp=temp->right;
				}else{
					break;
				}
			}else{
				if(temp->right){
					currXor+=(1<<j);
					temp=temp->right;
				}else if(temp->left){
					temp=temp->left;
				}else{
					break;
				}
			}
		}
		maxXor=max(maxXor , currXor);
		insert(root , xorTillNow);
	}
	return maxXor;
}
int main(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0 ; i<n ; i++) cin>>arr[i];
	cout<<maxXorSubArr(arr , n)<<'\n';
}