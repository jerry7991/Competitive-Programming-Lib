#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int solve(vector<int>& cost, int i, vector<int>& dp) {
        if (i >= cost.size()) {
            return 0;
        }
        
        int& ans = dp[i];
        if (ans != -1) return ans;
        ans = min(solve(cost, i + 1, dp), solve(cost, i + 2, dp));
        return ans += cost[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, -1);
        return min(solve(cost, 0, dp), solve(cost, 1, dp));
    }
};

int main() {
}