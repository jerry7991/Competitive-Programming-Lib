#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = 1e6;
        for (int j = i + 1; j < n && j < (i + nums[i] + 1); j++) {
            dp[i] = min(dp[i], 1 + dp[j]);
        }
    }
    return dp[0];
}

int jumpGreedy(vector<int>& nums) {
    int n = nums.size();
    int farthest = 0, currJumpEnd = 0, jumps = 0;
    for (int i = 0; i < n; i++) {
        farthest = max(farthest, nums[i]);

        if (i == currJumpEnd) {
            jumps++;
            currJumpEnd = farthest;
        }
    }
    return jumps;
}

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];
    cout << jump(num);
}