#include <bits/stdc++.h>
using namespace std;

class NumArray {
   public:
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        makeTree(tree, nums, 0, n - 1, 1);
    }

    void update(int index, int val) {
        update(index, val, 0, n - 1, 1);
    }

    int sumRange(int left, int right) {
        return getQuery(left, right, 0, n - 1, 1);
    }

    int getQuery(int lr, int rr, int l, int r, int it) {
        if (rr < l || lr > r) {
            return 0;
        }
        if (lr >= l && rr <= r) {
            return tree[it];
        }
        int m = (l + r) / 2;
        int left = getQuery(lr, rr, l, m, 2 * it);
        int right = getQuery(lr, rr, m + 1, r, 2 * it + 1);
        return (left + right);
    }

    void update(int index, int val, int l, int r, int it) {
        // if (index < l || index > r) return;
        if (l == r) {
            tree[it] = val;
            return;
        }
        int m = (l + r) / 2;
        if (m < index) {
            update(index, val, m + 1, r, it * 2 + 1);

        } else {
            update(index, val, l, m, 2 * it);
        }

        tree[it] = tree[it * 2] + tree[it * 2 + 1];
    }

    void makeTree(vector<int>& tree, vector<int>& nums, int i, int j, int itree) {
        if (i == j) {
            tree[itree] = nums[i];
            return;
        }

        int m = (i + j) / 2;

        makeTree(tree, nums, i, m, itree * 2);
        makeTree(tree, nums, m + 1, j, 2 * itree + 1);

        tree[itree] = tree[itree * 2] + tree[itree * 2 + 1];
    }
};
