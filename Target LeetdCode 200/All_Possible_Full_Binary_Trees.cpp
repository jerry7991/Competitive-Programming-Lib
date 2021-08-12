#include <bits/stdc++.h>

#include "TreeNode.h"
using namespace std;

class Solution {
   public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if (n < 1 || n % 2 == 0) {
            return ans;
        }
        for (int i = 2; i < n; i += 2) {
            vector<TreeNode*> leftSubTree = allPossibleFBT(i - 1);
            vector<TreeNode*> rightSubTree = allPossibleFBT(n - i);
            int l = leftSubTree.size(), r = rightSubTree.size();
            for (int j = 0; j < l; j++) {
                for (int k = 0; k < r; k++) {
                    TreeNode* root = new TreeNode(0);
                    root->left = leftSubTree[j];
                    root->right = rightSubTree[k];
                    ans.push_back(root);
                }
            }
        }

        if (ans.empty()) {
            if (n == 1) {
                ans.push_back(new TreeNode(0));
            }
        }
        return ans;
    }
};

void print(TreeNode* root) {
    if (!root) return;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode*> out = (new Solution())->allPossibleFBT(n);
    for (auto x : out) print(x);
    return 0;
}