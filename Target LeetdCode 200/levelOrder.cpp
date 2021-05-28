#include <bits/stdc++.h>

#include "TreeNode.h"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> level;
    vector<vector<int>> output;
    if (!root) return output;
    level.push(root);
    int n = 0;

    while (n = level.size()) {
        vector<int> lv;
        while (n--) {
            TreeNode* temp = level.front();
            level.pop();
            lv.push_back(temp->val);
            if (temp->left) level.push(temp->left);
            if (temp->right) level.push(temp->right);
        }
        output.push_back(lv);
    }
    return output;
}

int main() {
    TreeNode* root = takeInput();
    auto x = levelOrder(root);
    for (auto y : x) {
        for (auto z : y) cout << z << " ";
        cout << endl;
    }
}