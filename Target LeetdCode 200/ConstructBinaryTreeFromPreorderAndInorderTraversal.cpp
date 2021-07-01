#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    unordered_map<int, int> position;
    TreeNode *solve(vector<int> &preorder, int pre, int inS, int inE) {
        if (inS > inE) return nullptr;
        TreeNode *root = new TreeNode(preorder[pre]);
        int i = position[preorder[pre]], len = i - inS;

        root->left = solve(preorder, pre + 1, inS, i - 1);
        root->right = solve(preorder, pre + len + 1, i + 1, inE);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++) position[inorder[i]] = i;
        return solve(preorder, 0, 0, inorder.size() - 1);
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> preorder(n);
    vector<int> inorder(n);
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    TreeNode *root = (new Solution())->buildTree(preorder, inorder);
}