#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            int m = 0;
            for (int j = 1; j <= k && (i - j) >= 0; j++) {
                m = max(m, nums[i - j]);
                dp[i] = max(dp[i], dp[i - j] + m * j);
            }
        }
        return dp[n];
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->maxSumAfterPartitioning(nums, k);
}