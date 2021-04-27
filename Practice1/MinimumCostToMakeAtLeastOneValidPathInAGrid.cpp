#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

int solve(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp, vector<vector<bool>>& vis) {
    int n = grid.size(), m = grid[0].size();
    if (min(row, col) < 0 || row >= n || col >= m || vis[row][col]) {
        return 1e6;
    }
    if (row == n - 1 && col == m - 1) {
        return 0;
    }
    if (dp[row][col] >= 0) {
        return dp[row][col];
    }
    vis[row][col] = true;
    int ans = 1e6;

    for (int i = 1; i <= 4; i++) {
        ans = min(ans, solve(grid, row + dx[i - 1], col + dy[i - 1], dp, vis) + (grid[row][col] != i));
    }
    return dp[row][col] = ans;
}

int minCost(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
    return solve(grid, 0, 0, dp, vis);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << minCost(grid);
}