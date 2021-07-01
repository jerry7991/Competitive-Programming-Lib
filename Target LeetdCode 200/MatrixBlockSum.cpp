#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int i = 0; i <= m; i++) dp[0][i] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = mat[i - 1][j - 1] - dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                mat[i - 1][j - 1] = dp[min(i + k, n)][min(j + k, m)] - dp[min(i + k, n)][max(j - k - 1, 0)] - dp[max(0, i - k - 1)][min(j + k, m)] + dp[max(i - k - 1, 0)][max(0, j - k - 1)];
            }
        }
        return mat;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> mat[i][j];

    auto x = (new Solution())->matrixBlockSum(mat, k);
    for (auto y : x) {
        for (auto z : y) cout << z << " ";
        cout << endl;
    }
}