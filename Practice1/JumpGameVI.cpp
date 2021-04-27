#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int k, int idx, vector<int>& dp) {
    int sum = 0;
    for (int i = idx; i < (idx + k); i++) {
        if (i < nums.size()) {
            sum = max(sum, nums[idx] + solve(nums, k, i + 1, dp));
        }
    }
    return sum;
}

int maxResult1(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(nums, k, 0, dp);
}

int maxResult2(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    for (int i = 1; i <= k; i++) {
        dp[i] = INT_MIN;
        for (int j = i - 1; j >= 0; j--) {
            dp[i] = (dp[i], nums[i] + dp[j]);
        }
    }
    for (int i = k + 1; i < n; i++) {
        dp[i] = INT_MIN;
        for (int j = i - k - 1; j < i; j++) {
            dp[i] = max(dp[i], nums[i] + dp[j]);
        }
    }
    int ans = dp[n - 1];
    dp.clear();
    return ans;
}

int maxResult(vector<int>& nums, int k) {
    deque<int> window{0};
    for (int i = 1; i < nums.size(); i++) {
        if (window.front() + k < i) {
            window.pop_front();  // trim from left to mantain window of size k
        }
        nums[i] += nums[window.front()];
        while (window.size() && nums[i] >= nums[window.back()]) {
            window.pop_back();
        }
        // Add current to the window of size of k
        window.push_back(i);
    }
    return nums.back();
}
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int k;
    cin >> k;
    cout << maxResult(v, k);
}