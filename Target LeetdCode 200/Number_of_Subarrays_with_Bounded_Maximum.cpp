#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size(), prev = 0, sum = 0;
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] < left) {
                dp[i] = dp[i - 1];
            }
            if (nums[i - 1] > right) {
                dp[i] = 0;
                prev = i;
            }
            if (nums[i - 1] >= left && nums[i - 1] <= right) {
                dp[i] += i - prev;
            }
            sum += dp[i];
        }
        return sum;
    }
};

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->numSubarrayBoundedMax(nums, l, r);
}