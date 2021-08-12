#include<bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
	vector<vector<int>> ans;

	void solve(TreeNode * root, int sum , vector<int> &path) {
		if (!root) {
			return;
		}

		sum = sum - root->val;
		path.push_back(root->val);

		if (sum == 0 && !root->left && !root->right) {
			ans.push_back(path);
		}


		solve(root->left, sum, path);
		solve(root->right, sum, path);
		path.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<int> path;
		solve(root, targetSum, path);
		return ans;
	}
};