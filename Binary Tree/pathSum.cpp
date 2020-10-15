#include<bits/stdc++.h>
#include "Tree.h"
using namespace std;
bool isSum(Tree<int> *root , int sum , int currSum=INT_MIN){
  if(currSum==INT_MIN) currSum=0;
  if(!root) return false;
	if(!root->left && !root->right){
		return currSum+root->val==sum;
	}
	bool ans=false;
  if(root->left){
    ans |=hasPathSum(root->left , sum , currSum+root->val);
    if(ans)
      return ans;
  }
  if(root->right){
    ans |=hasPathSum(root->right , sum , currSum+root->val);
  }
  return ans;
}
int main(){
	int sum;cin>>sum;
	Tree<int> *root=takeInput();
	cout<<isSum(root , sum)<<'\n';
}