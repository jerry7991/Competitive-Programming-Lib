#include<iostream>
#include<vector>
using namespace std;
class Tries{
  public:
    Tries *left;//0 bit for left
    Tries *right;//1 bit for right
    Tries(){
      left=right=NULL;
    }
};
void insert(Tries * root , int  number ){
  for(int i=31 ; i>=0 ; i--){
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
int helper(Tries *root , int n){
  int maxXor=0;
  for(int i=31 ; i>=0 ; i--){
    int currBit=(n>>i)&1;
    if(currBit){
      if(root->left){
        maxXor+=(1<<i);
        root=root->left;
      }else if(root->right){
        root=root->right;
      }
    }else{
      if(root->right){
        maxXor+=(1<<i);
        root=root->right;
      }else if(root->left){
        root=root->left;
      }
    }
  }
  return maxXor;
}
int solve(vector<int> &nums ){
  int n=nums.size() , maxXor=0;
  if(n==0 || n==1) return maxXor;
  if(n==2) return nums[0]^nums[1];
  Tries *root=new Tries();
  for(int i=0 ; i<n ; i++) insert(root , nums[i]);
  for(int i=0 ; i<n ; i++) maxXor=max(maxXor , helper(root , nums[i]));
  return maxXor;
}
int main(){
  int n;cin>>n;
  vector<int> v;
  for(int i=0 ; i< n ; i++){
    int x;cin>>x;
    v.push_back(x);
  }
  cout<<solve(v)<<endl;
  return 0;
}