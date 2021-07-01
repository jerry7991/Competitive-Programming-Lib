#include <bits/stdc++.h>
using namespace std;

// Using dp
class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), d = 0;
        vector<vector<int>> dp(n, vector<int>(m, n * m));

        //  First go for top to bottom
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) dp[i][j] = 0;
                dp[i][j] = min(dp[i][j], 1 + min((i ? dp[i - 1][j] : (n * m)), (j ? dp[i][j - 1] : (n * m))));
            }
        }

        // For bottom to up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i < n - 1)
                    dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j]);
                if (j < m - 1)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j + 1]);
            }
        }
        return dp;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> mat[i][j];
    auto x = (new Solution())->updateMatrix(mat);
    for (auto y : x) {
        for (auto z : y) cout << z << " ";
        cout << endl;
    }
}