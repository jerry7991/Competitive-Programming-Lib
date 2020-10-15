#include<bits/stdc++.h>
using namespace std;
class Tries{
public:
	Tries *left,*right;
};
void insert(Tries* root , int number){
	Tries *temp=root;
	for(int i=31 ; i>=0; i--){
		int currBit=(number>>i)&1;
		if(currBit){
			if(!temp->right){
				temp->right=new Tries();
			}
			temp=temp->right;
		}else{
			if(!temp->left){
				temp->left=new Tries();
			}
			temp=temp->left;
		}
	}
}
int findMaximumXOR(vector<int>& nums) {
   int maxXor=INT_MIN , currXor=0;
   Tries *root=new Tries();
   insert(root,nums[0]);
   for(int i=1 ; i<nums.size() ; i++){
   	Tries *temp=root;
   	currXor=0;
   	for(int j=31 ; j>=0 ; j--){
   		int currBit=(nums[i]>>j)&1;
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
   	insert(root , nums[i]);
   	maxXor=max(currXor , maxXor);
   }
   return maxXor;
}
int main(){
   int t;
   cin>>t;
   while(t--){
	int n;cin>>n;
	vector<int> v;
	for(int i=0 ;i<n ; i++){
		int x;cin>>x;
		v.push_back(x);
	}
	cout<<findMaximumXOR(v)<<'\n';
}
}