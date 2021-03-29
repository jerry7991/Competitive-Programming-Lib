#include <iostream>
#include <unordered_map>
using namespace std;
#include "TreeNode.h"
int solve(TreeNode<int> *root , unordered_map<TreeNode<int>* , int> &dp, bool robbed = false) {
	if(!root){
		return 0;
	}
	if (robbed) {
		return ( solve(root->left , dp, !robbed) + solve(root->right , dp, !robbed) );
	}
	if(dp.count(root)>0){
		return dp[root];
	}
	int include = root->val + solve(root->left , dp, !robbed) + solve(root->right, dp, !robbed);
	int exclude = solve(root->left , dp, robbed) + solve(root->right , dp, robbed);
	return dp[root]=max(include , exclude);
}
int rob(TreeNode<int> *root , bool robbed = false) {
	if (!root) {
		return 0;
	}
	unordered_map<TreeNode<int> *, int> dp;
	return solve(root , dp );
}
int main() {
	TreeNode<int> *root = takeInput();
	cout << rob(root) << endl;
}