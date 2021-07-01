#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void update(int i, int value, vector<int>& tree, int size) {
        i += size;
        tree[i] += value;
        while (i > 1) {
            i /= 2;
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    int query(int l, int r, vector<int>& tree, int size) {
        l += size, r += size;  // go to leaves;
        int ans = 0;
        while (l < r) {
            if (l % 2 == 1) {
                ans += tree[l];  // All left will be smaller
                l++;
            }
            l /= 2;
            if (r % 2 == 1) {
                r--;
                ans += tree[r];
            }
            r /= 2;
        }
        return ans;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int offset = 1e4;
        int size = 2 * (2 * offset + 1);
        vector<int> tree(2 * size, 0);
        vector<int> out(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int smallCount = query(0, nums[i] + offset, tree, size);
            out[i] = smallCount;
            update(nums[i] + offset, 1, tree, size);
        }
        return out;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<int> ans = (new Solution())->countSmaller(nums);
    for (auto x : ans) cout << x << " ";
}
