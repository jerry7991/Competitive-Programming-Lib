#include<bits/stdc++.h>
#include "Tree.h"
using namespace std;
vector<vector<int>> output;
void solve(Tree<int>*root ,int sum ,vector<int> v ,int currSum=INT_MIN){
  if(currSum==INT_MIN){
    currSum=0;
  }
  v.push_back(root->data);
  currSum+=root->data;
  if(!root->left && !root->right ){
    if(currSum!=sum) return;
    output.push_back(v);
    return;
  }
  if(root->left){
    solve(root->left , sum , v ,currSum);
  }
  if(root->right){
    solve(root->right , sum , v ,currSum);
  }
}
vector<vector<int>> pathSum(Tree<int>* root, int sum) {
  if(!root) return output;
  vector<int>v;
  solve(root , sum , v);
  return output;
}
int main(){
	int sum;cin>>sum;
	Tree<int> *root=takeInput();
  vector<vector<int>> v=pathSum(root , sum);
  for(int i=0 ; i<v.size() ;i++){
    for(int j=0 ; j<v[i].size() ; j++){
      cout<<v[i][j]<<' ';
    }
    cout<<'\n';
  }
}