#include <bits/stdc++.h>

#include "TreeNode.h"
using namespace std;

pair<int, TreeNode*> solve(TreeNode* root) {
    if (!root) return {0, nullptr};

    pair<int, TreeNode*> left = solve(root->left);
    pair<int, TreeNode*> right = solve(root->right);

    pair<int, TreeNode*> ans;

    if (left.first > right.first) {
        ans = {left.first + 1, left.second};
    } else if (left.first == right.first) {
        ans = {left.first + 1, root};
    } else {
        ans = {right.first + 1, right.second};
    }
    return ans;
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return solve(root).second;
}

int main() {
    TreeNode* root = takeInput();
    root = subtreeWithAllDeepest(root);
    printPreOrder(root);
}