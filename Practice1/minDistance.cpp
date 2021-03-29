#include<bits/stdc++.h>
#include "Tree.h"
using namespace std;
int maxVal(Tree<int> *root) {
	int m = INT_MAX;
	while (root) {
		m = root->val;
		root = root->right;
	}
	return m;
}
int minVal(Tree<int> *root) {
	int m = INT_MAX;
	while (root) {
		m = root->val;
		root = root->left;
	}
	return m;
}

void getMin(int &curr, Tree<int>*root) {
	if (!root) return ;
	curr = min(curr, min(abs(root->val - maxVal(root->left)), abs(root->val - minVal(root->right))));
	getMin(curr, root->left);
	getMin(curr, root->right);
}

int minDiffInBST(Tree<int>* root) {
	int curr = INT_MAX;
	getMin(curr , root);
	return curr;
}
int main() {
	Tree<int> root = takeInput();
	cout << minDiffInBST(root) << endl;
	return 0;
}
