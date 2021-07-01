#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int solve(int floor, int egg, vector<vector<int>> &dp) {
        if (egg == 1 || floor <= 1) {
            return floor;
        }
        int &ans = dp[egg][floor];
        if (ans != INT_MAX) return ans;
        for (int i = 1; i <= floor; i++) {
            int breakEgg = solve(i - 1, egg - 1, dp);
            int notBreakEgg = solve(floor - i, egg, dp);
            ans = min(ans, 1 + max(breakEgg, notBreakEgg));
        }
        return ans;
    }

    int twoEggDrop(int n) {
        int egg = 2, flag = 1;
        vector<vector<int>> dp(egg + 1, vector<int>(n + 1, INT_MAX));
        return solve(n, egg, dp);
    }
};

int main() {
    int n;
    cin >> n;
    cout << (new Solution())->twoEggDrop(n) << endl;
}