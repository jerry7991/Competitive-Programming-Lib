#include <iostream>
#include <vector>
using namespace std;
#include "TreeNode.h"
int getMax(vector<int> &arr, int left, int right) {
	if(left>right) return 0;
	return max(arr[left]+getMax(arr , left+2,right) , getMax(arr , left+1,right));
}
int rob(TreeNode<int>* root) {
	int ans = 0;
	if (!root) return ans;
	vector<int> level;
	queue<TreeNode<int>*>	q;
	q.push(root);
	while (!q.empty()) {
		int n = q.size();
		ans = 0;
		while (n--) {
			TreeNode<int> *temp = q.front();
			q.pop();
			ans += temp->val;
			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
		}
		level.push_back(ans);
	}
	return max(getMax(level , 0 , level.size() - 1) , getMax(level , 1, level.size() - 1));
}
int main() {
	TreeNode<int> *root = takeInput();
	cout << rob(root) << '\n';
}