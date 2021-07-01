#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int n, int i, int last, string &str) {
        if (i == n) return 1;
        int ans = 0;
        for (int j = last; j < str.size(); j++) {
            ans += solve(n, i + 1, j, str);
        }
        return ans;
    }

   public:
    int countVowelStrings(int n) {
        string str = "aeiou";
        // return solve(n, 0, 0, str);

        // Optimized
        vector<vector<int>> dp(5, vector<int>(n));
        for (int i = 0; i < 5; i++) dp[i][0] = i + 1;
        for (int i = 0; i < n; i++) dp[0][i] = 1;
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = 0;
                for (int k = i; k >= 0; k--) dp[i][j] += dp[k][j - 1];
            }
        }
        return dp[5][n];
    }

   public:
    int countVowelStrings(int n) {
        return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
    }
};

int main() {
    int n;
    cin >> n;

    cout << (new Solution())->countVowelStrings(n);
}