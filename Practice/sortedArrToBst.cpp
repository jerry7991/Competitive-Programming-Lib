#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
TreeNode<int> * solve(vector<int> &nums , int i, int n) {
	if (i > n) {
		return NULL;
	}
	int mid = (i + n) / 2;
	TreeNode<int> *root = new TreeNode<int>(nums[mid]);
	root->left = solve(nums , i, mid - 1);
	root->right = solve(nums, mid + 1, n);
	return root;
}
TreeNode<int>* sortedArrayToBST(vector<int>& nums) {
	return solve(nums , 0 , nums.size() - 1);
}
void inorder(TreeNode<int> *root) {
	if (!root) return;
	inorder(root->left);
	cout << root->val << ' ';
	inorder(root->right);
}
void printLevelOrder(TreeNode<int> *root) {
	queue<TreeNode<int>*> q;
	q.push(root);
	while (q.size()) {
		TreeNode<int> *temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if (temp->left) {
			q.push(temp->left);
		}
		if (temp->right) {
			q.push(temp->right);
		}
	}
}
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	TreeNode<int> *root = sortedArrayToBST(nums);
	inorder(root);
	return 0;
}