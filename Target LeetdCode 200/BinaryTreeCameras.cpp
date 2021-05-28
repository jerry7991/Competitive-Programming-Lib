#include <bits/stdc++.h>

#include "TreeNode.h"
using namespace std;

void solve(TreeNode* root, TreeNode* parent, unordered_set<TreeNode*>& visited, int& ans) {
    if (!root) return;
    solve(root->left, root, visited, ans);
    solve(root->right, root, visited, ans);

    if ((parent == NULL && visited.count(root) == 0) || visited.count(root->left) == 0 || visited.count(root->right) == 0) {
        ans++;
        visited.insert(root);
        visited.insert(parent);
        visited.insert(root->left);
        visited.insert(root->right);
    }
}

int minCameraCover(TreeNode* root) {
    unordered_set<TreeNode*> visited;
    visited.insert(NULL);
    int ans = 0;
    solve(root, NULL, visited, ans);
    return ans;
}

int main() {
    TreeNode* root = takeInput();
    cout << minCameraCover(root);
}