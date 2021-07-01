#include <bits/stdc++.h>

#include "TreeNode.h"
using namespace std;

class Solution {
   public:
    int ans = 0;
    int solve(TreeNode* root) {
        if (!root) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        int curr = root->val;
        ans += abs(right - left);
        root->val = abs(right - left);
        return left + right + curr;
    }

    int getSum(TreeNode* root) {
        if (!root) return 0;
        int left = getSum(root->left);
        int right = getSum(root->right);
        return left + right + root->val;
    }

    int findTilt(TreeNode* root) {
        int ans = solve(root);
        return getSum(root);
    }
};

int main() {
    TreeNode* root = takeInput();
    cout << (new Solution())->findTilt(root);
}