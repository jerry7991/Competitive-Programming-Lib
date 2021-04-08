#include <bits/stdc++.h>

#include "TreeNode.h"
using namespace std;

void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
    if (!root) return;
    if (root->left) parent[root->left] = root;
    if (root->right) parent[root->right] = root;
    dfs(root->left, parent);
    dfs(root->right, parent);
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    unordered_map<TreeNode*, TreeNode*> parent;

    vector<TreeNode*> leaf;
    dfs(root, parent);
    unordered_set<TreeNode*> visited;
    queue<TreeNode*> level;
    level.push(root);

    while (level.size()) {
        int n = level.size();
        vector<TreeNode*> curr;
        for (int i = 0; i < n; i++) {
            TreeNode* temp = level.front();
            level.pop();
            curr.push_back(temp);

            if (temp->left) level.push(temp->left);
            if (temp->right) level.push(temp->right);
        }
        leaf = curr;
    }

    for (int i = 0; i < leaf.size(); i++) level.push(leaf[i]);
    TreeNode* ans = NULL;
    while (level.size() > 1) {
        int n = level.size();
        for (int i = 0; i < n; i++) {
            TreeNode* temp = level.front();
            ans = temp;
            level.pop();
            if (visited.count(parent[temp]) == 0) {
                level.push(parent[temp]);
                visited.insert(parent[temp]);
            }
        }
    }
    return level.front();
}

int main() {
    TreeNode* root = takeInput();
    root = subtreeWithAllDeepest(root);
    printPreOrder(root);
}