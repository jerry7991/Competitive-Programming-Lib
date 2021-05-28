#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int i, j, l, ans = INT_MIN;
        for (i = 0; i < n; i++) {
            dp[i] = nums[i];
            for (j = i - 1, l = k; j >= 0 && l > 0; --j, --l) {
                dp[i] = max(dp[j] + nums[i], dp[i]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    // Using heap
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ans = nums[0];
        vector<int> dp(n);
        deque<int> kWindow;
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
            if (kWindow.size()) {
                dp[i] += dp[kWindow.front()];
            }
            ans = max(ans, dp[i]);
            if (kWindow.size() && (i - k + 1) > kWindow.front()) kWindow.pop_front();
            while (kWindow.size() && dp[kWindow.back()] <= dp[i]) kWindow.pop_back();

            if (dp[i] > 0)
                kWindow.push_back(i);
        }
        return ans;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->constrainedSubsetSum(nums, k);
    return 0;
}