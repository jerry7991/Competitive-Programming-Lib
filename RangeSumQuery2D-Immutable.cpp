#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
    vector<vector<int>> sum;
    int n, m;

   public:
    NumMatrix(vector<vector<int>>& matrix) {
        solve(matrix);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - (sum[row1][col2 + 1] + sum[row2 + 1][col1] - sum[row1][col1]);
    }

    void solve(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        sum.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            sum[i].resize(m + 1);
        }
        for (int i = 0; i <= n; i++) sum[i][0] = 0;
        for (int i = 0; i <= m; i++) sum[0][i] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + matrix[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] += sum[i][j - 1];
            }
        }
    }
};

int main() {
}