#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool solve(vector<int>& nums, int w, int x, int y, int z, int i) {
        if (i == nums.size()) {
            return (x == y && y == z && x == w) && i > 3;
        }
        return solve(nums, w + nums[i], x, y, z, i + 1) ||
               solve(nums, w, x + nums[i], y, z, i + 1) ||
               solve(nums, w, x, y + nums[i], z, i + 1) ||
               solve(nums, w, x, y, z + nums[i], i + 1);
    }
    bool makesquare(vector<int>& nums) {
        return solve(nums, 0, 0, 0, 0, 0);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
}