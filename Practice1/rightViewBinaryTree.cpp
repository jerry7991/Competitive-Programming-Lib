#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

vector<int> rightSideView(TreeNode* root) {
	vector<int>ans;
	if(!root) return ans;
	queue<TreeNode *> level;
	level.push(root);
	while (level.size()) {
		int n = level.size();
		while (n--) {
			TreeNode * temp = level.front();
			level.pop();

			if (temp->left) {
				level.push(temp->left);
			}
			if (temp->right) {
				level.push(temp->right);
			}
			if (n == 0) {
				ans.push_back(temp->val);
			}
		}
	}
	return ans;
}

void solve() {
	TreeNode * root = takeInput();

	cout<<"Pre Order Is ::"<<endl;
	printPreOrder(root);

	vector<int> ans = rightSideView(root);

	for(int i=0;i<ans.size();i++){
		cout<<ans[i];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) solve();
	return 0;
}