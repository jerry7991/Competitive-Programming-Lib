#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dx = {1, 1, 1};
    vector<int> dy = {-1, 0, 1};
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (j < 0 || j >= matrix[0].size()) {
            return 1000000;
        }
        if (i == matrix.size() - 1) {
            return matrix[i][j];
        }
        int& ans = dp[i][j];
        if (ans != 1000000) return ans;

        for (int k = 0; k < 3; k++) {
            ans = min(ans, matrix[i][j] + helper(matrix, dp, i + dx[k], j + dy[k]));
        }
        return ans;
    }

    int solve(vector<vector<int>>& matrix, int i) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1000000));
        return helper(matrix, dp, 0, i);
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = 1000000;
        for (int i = 0; i < matrix[0].size(); i++) {
            ans = max(ans, solve(matrix, i));
        }
        return ans;
    }

    //  Optimise
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0)
                    matrix[i][j] += min({j > 0 ? matrix[i - 1][j - 1] : INT_MAX, matrix[i - 1][j], j + 1 < m ? matrix[i - 1][j + 1] : INT_MAX});
                if (i == n - 1)
                    ans = min(ans, matrix[i][j]);
            }
        }
        return ans;
    }
};

int main() {
}