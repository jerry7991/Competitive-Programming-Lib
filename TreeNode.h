#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode * takeInput() {
	queue<TreeNode*> q;
	int val;
	cin >> val;
	if (val == -1) return NULL;
	TreeNode *root = new TreeNode(val);
	q.push(root);
	while (q.size()) {
		TreeNode *temp = q.front();
		q.pop();
		cin >> val;
		if (val != -1) {
			temp->left = new TreeNode(val);
			q.push(temp->left);
		} else {
			temp->left = NULL;
		}
		cin >> val;
		if (val != -1) {
			temp->right = new TreeNode(val);
			q.push(temp->right);
		} else {
			temp->right = NULL;
		}
	}
	return root;
}
void printPreOrder(TreeNode* root) {
	if (!root) return;
	cout << root->val << " ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}
void printInOrder(TreeNode* root) {
	if (!root) return;
	printInOrder(root->left);
	cout << root->val << " ";
	printInOrder(root->right);
}
void printPostOrder(TreeNode* root) {
	if (!root)return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->val << " ";
}
void printLevelOrder(TreeNode* root) {
	queue<TreeNode*> level;
	if (root)level.push(root);
	int n;
	while (n = level.size()) {
		while (n--) {
			TreeNode* temp = level.front();
			level.pop();
			cout << temp->val << " ";
			if (temp->left) level.push(temp->left);
			if (temp->right) level.push(temp->right);
		}
	}
}