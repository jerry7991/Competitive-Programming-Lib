#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

void solve(TreeNode* root, int &mVal, int &prev) {
	if (!root) return;
	solve(root->left, mVal, prev);
	if (prev != INT_MIN) {
		mVal = min(mVal, root->val - prev);
	}
	prev = root->val;
	solve(root->right, mVal, prev);
}

int minDiffInBST(TreeNode* root) {
	int prev  = INT_MIN, mVal = INT_MAX;
	solve(root, mVal, prev);
	return mVal;
}

int main() {
	TreeNode * root = takeInput();
	cout << minDiffInBST(root) << endl;
	return 0;
}
