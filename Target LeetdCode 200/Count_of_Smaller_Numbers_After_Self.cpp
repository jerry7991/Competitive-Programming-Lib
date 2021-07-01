#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int getCount(vector<int>& tree, int l, int r, int size) {
        l += size, r += size;
        int ans = 0;
        while (l < r) {
            if (l & 1) {
                ans += tree[l];
                l++;
            }
            l /= 2;
            if (r & 1) {
                r--;
                ans += tree[r];
            }
            r /= 2;
        }
        return ans;
    }

    void update(int i, int value, vector<int>& tree, int size) {
        i += size;
        tree[i] += value;
        while (i > 1) {
            i /= 2;
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        int minValue = 1e4, size = 2 * (2 * 1e4 + 1);
        vector<int> tree(2 * size, 0);
        vector<int> out(n);
        for (int i = n - 1; i >= 0; i--) {
            out[i] = getCount(tree, 0, nums[i] + minValue, size);
            update(nums[i] + minValue, 1, tree, size);
        }
        return out;
    }
};

int main() {
    int n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<int> out = (new Solution())->countSmaller(nums);
    for (int x : out) cout << x << " ";
}