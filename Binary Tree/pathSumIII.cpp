#include<bits/stdc++.h>
#include "Tree.h"
using namespace std;
int solve(Tree<int>*root ,int sum ,int currSum=INT_MIN){
  if(currSum==INT_MIN){
    currSum=0;
  }
  currSum+=root->data;
  if(!root->left && !root->right ){
     return(currSum==sum);
  }
  int ans=(currSum==sum); 
  if(root->left){
    ans+=solve(root->left , sum ,currSum);
    ans+=solve(root->left , sum ,0);
  }
  if(root->right){
    ans+=solve(root->right , sum ,currSum);
    ans+=solve(root->right , sum ,0);
  }
  return ans;
}
int pathSum(Tree<int>* root, int sum) {
  if(!root) return 0;
  return solve(root , sum);
}
int main(){
	int sum;cin>>sum;
	Tree<int> *root=takeInput();
  cout<<pathSum(root , sum)<<'\n';
}
/*

*/