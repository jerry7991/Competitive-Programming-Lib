#include <bits/stdc++.h>

#include "TreeNode.h"

using namespace std;

int findBottomLeftValue(TreeNode* root) {
    int ans = INT_MAX;
    queue<TreeNode*> level;
    if (root) level.push(root);

    while (level.size()) {
        int n = level.size();
        for (int i = 0; i < n; i++) {
            TreeNode* temp = level.front();
            level.pop();
            if (!i) ans = temp->val;
            if (temp->left) level.push(temp->left);
            if (temp->right) level.push(temp->right);
        }
    }
    return ans;
}
int main() {
    TreeNode* root = takeInput();
    cout << findBottomLeftValue(root);
}