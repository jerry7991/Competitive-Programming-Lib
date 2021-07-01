#include <bits/stdc++.h>
using namespace std;

/*
    s1 = abc  
    s2 = abcd

    s3 = aabbccd

    Intution: 
    For making s3[k] what we have,
    suppose we have used s1[0...i) and s2[0...j) for making s3[0...k)
    So we have three condition for making s3[k]
    1.  s1[i] == s2[j] == s3[k], so we have 2 option
        i. whether we use s1[i] to make s3[k], 
        ii. or we can use s2[j] to make s3[k]
    2. if none of s1[i] and s2[j] is able to make s3[k]
        i. We can't make s3 for now.
    3. If s1[i] is able to make s3[k] then use s1[i] else use s2[j]
*/

class Solution {
   public:
    vector<vector<int>> dp;
    bool solve(string& s1, string& s2, string& s3, int i, int j, int k) {
        if (k == s3.size()) {
            return i == s1.size() && j == s2.size();
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (i >= s1.size()) {
            if (s2[j] != s3[k]) {
                return dp[i][j] = false;
            } else {
                return dp[i][j] = solve(s1, s2, s3, i, j + 1, k + 1);
            }
        } else if (j >= s2.size()) {
            if (s1[i] != s3[k]) {
                return dp[i][j] = false;
            } else {
                return dp[i][j] = solve(s1, s2, s3, i + 1, j, k + 1);
            }
        } else {
            if (s1[i] != s3[k] && s2[j] != s3[k]) {
                return dp[i][j] = false;
            }
        }

        bool ans = false;
        if (s1[i] == s2[j]) {
            ans |= solve(s1, s2, s3, i + 1, j, k + 1);
            ans |= solve(s1, s2, s3, i, j + 1, k + 1);
        } else {
            if (s1[i] == s3[k]) {
                ans |= solve(s1, s2, s3, i + 1, j, k + 1);
            } else {
                ans |= solve(s1, s2, s3, i, j + 1, k + 1);
            }
        }
        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(s1.size() + 1);
        for (int i = 0; i <= s1.size(); i++) {
            dp[i].resize(s2.size() + 1);
            for (int j = 0; j <= s2.size(); j++) dp[i][j] = -1;
        }
        // return solve(s1, s2, s3, 0, 0, 0);

        // Solve optimise

        return solve(s1, s2, s3);

        // Most Optimised
    }

    /*
    If we look carefully recursive solution then how dp is filling.
    dp[i][j] is filled by 
    1. solve(i+1,j,k+1) || solve(i,j+1,k+1) // When both s1[i] and s2[i] is able to make s3[k]
    2. solve(i+1,j,k+1) // When only s1[i] only able to make s3[k]
    3. solve(i,j+1, k + 1) // When only s2[j] only able to make s3[k]

    So we can fill dp iterative also
*/
    bool solve(string s1, string s2, string s3) {
        int l = s1.size(), m = s2.size(), n = s3.size();
        if (l + m != n) return false;

        vector<vector<bool>> dp(l + 1, vector<bool>(m + 1));

        for (int i = 0; i <= l; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                } else if (j == 0) {
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                } else {
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[l][m];
    }

    /*
    Now if we look the dependency of dp[i][j] then
    dp[i][j] -> dp[i-1][j], dp[i][j-1] only, so we can skip all the remove which are less than i-1 because we don't need them
*/

    bool solveOP(string s1, string s2, string s3) {
        int l = s1.size(), m = s2.size(), n = s3.size(), flag = 1;
        vector<vector<bool>> dp(2, vector<bool>(m + 1));

        for (int i = 0; i <= l; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) {
                    dp[flag][j] = true;
                } else if (i == 0) {
                    dp[flag][j] = (dp[flag ^ 1][j] && (s2[j - 1] == s3[i + j - 1]));
                } else if (j == 0) {
                    dp[flag][j] = (dp[flag ^ 1])[j] && (s1[i - 1] == s3[i + j - 1]);
                } else {
                    dp[flag][j] = ((dp[flag ^ 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[flag][j - 1] && (s2[j - 1] == s3[i + j - 1])));
                }
            }
            flag ^= 1;
        }
        return dp[flag ^ 1][m];
    }
};

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << (new Solution())->isInterleave(s1, s2, s3);
}