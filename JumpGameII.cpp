#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = 1001;
        if (nums[i] == 0) continue;
        for (int j = i + 1; j < n && j < nums[i] - i; j++) {
            dp[i] = min(dp[i], 1 + dp[j]);
        }
    }
    return dp[0];
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << jump(nums);
}