#include <bits/stdc++.h>

#include "TreeNode.h"
using namespace std;

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> level;

    while (true) {
        while (root) {
            level.push(root);
            root = root->left;
        }
        root = level.top();
        level.pop();
        if (--k == 0) {
            return root->val;
        }
        if (root->right)
            level.push(root->right);
    }
}

int main() {
    cout << "Hi";
    TreeNode* root = takeInput();
    int k;
    cin >> k;
    cout << kthSmallest(root, k) << endl;
    return 0;
}
