#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool solve(vector<int>& nums, vector<int>& edge, int target, int i = 0) {
        if (i == nums.size()) {
            return edge[0] == edge[1] && edge[1] == edge[2] && edge[2] == edge[3];
        }
        bool ans = false;
        for (int j = 0; j < 4; j++) {
            if (edge[j] + nums[i] > target) continue;
            edge[j] += nums[i];
            ans |= solve(nums, edge, target, i + 1);
            edge[j] -= nums[i];
            if (ans) return ans;
        }
        return ans;
    }

    bool makesquare(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i : nums) sum += i;
        if (n < 4 || sum % 4) return false;
        sort(nums.begin(), nums.end());
        vector<int> edge(4, 0);
        return solve(nums, edge, sum / 4);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
}