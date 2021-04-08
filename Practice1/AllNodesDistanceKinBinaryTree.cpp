#include <bits/stdc++.h>

#include "TreeNode.h"
using namespace std;

void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
    if (!root) return;
    if (root->left) {
        parent[root->left] = root;
    }
    if (root->right) {
        parent[root->right] = root;
    }
    dfs(root->left, parent);
    dfs(root->right, parent);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent;  // Parent(x)=>y

    dfs(root, parent);

    vector<int> out;

    unordered_set<TreeNode*> vist;

    queue<TreeNode*> level;
    level.push(target);
    vist.insert(target);
    while (level.size() && k >= 0) {
        int n = level.size();
        for (int i = 0; i < n; i++) {
            TreeNode* curr = level.front();
            level.pop();
            if (k == 0) {
                out.push_back(curr->val);
            }
            vist.insert(curr);
            if (vist.count(parent[curr]) == 0 && parent[curr]) level.push(parent[curr]);
            if (vist.count(curr->left) == 0 && curr->left) level.push(curr->left);
            if (vist.count(curr->right) == 0 && curr->right) level.push(curr->right);
        }
        k--;
    }
    return out;
}

int main() {
    TreeNode* root = takeInput();
    int t, k;
    cin >> t >> k;
    TreeNode* target = new TreeNode(t);
    vector<int> output = distanceK(root, target, k);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
}