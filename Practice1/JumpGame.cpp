#include <bits/stdc++.h>
using namespace std;

bool solve(int curr, vector<int>& nums) {
    if (nums.size() <= curr) {
        return (nums.size() == curr);
    }

    bool ans = false;

    for (int i = 1; i <= nums[curr]; i++) {
        ans |= solve(curr + i, nums);
        if (ans) break;
    }
    return ans;
}

int solveOP(int curr, vector<int>& dp, vector<int>& nums) {
    if (nums.size() - 1 <= curr) {
        return (nums.size() - 1 == curr) ? 1 : 0;
    }

    if (dp[curr] >= 0) {
        return dp[curr];
    }

    int ans = -1;

    for (int i = 1; i <= nums[curr]; i++) {
        ans = solveOP(curr + i, dp, nums);
        if (ans != -1) break;
    }
    return dp[curr] = ans;
}

bool canJump(vector<int>& nums) {
    if (nums.size() == 1) return true;
    vector<int> dp(nums.size(), -1);
    return solveOP(0, dp, nums) == 1;
}

bool canJump1(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i++) {
        dp[i] = 0;
        for (int j = i + 1; j < n && j < (i + nums[i]); j++) {
            if (dp[j] == 1) {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[0];
}

bool canJumpGreedy(vector<int>& nums) {
    int n = nums.size();
    int rightMostReachable = n - 1;
    vector<int> dp(n);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (rightMostReachable - i > nums[i]) {
            dp[i] = 0;
        } else {
            dp[i] = 1;
            rightMostReachable = i;
        }
    }
    return dp[0];
}

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];
    cout << canJump(num);
}