#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool isValid(int i, int j, int n, int m) {
        return min(i, j) >= 0 && i < n && j < m;
    }

    int solve(vector<vector<int>>& grid, vector<vector<bool>>& seen, int i, int j, int last) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return (last >= grid[i][j]) ? 0 : (grid[i][j] - last);
        }

        int ans = 1e6;
        seen[i][j] = true;
        int temp = (last >= grid[i][j]) ? 0 : (grid[i][j] - last);
        last = max(last, grid[i][j]);
        for (int k = 0; k < 4; k++) {
            int r = i + dx[k], c = j + dy[k];
            if (isValid(r, c, grid.size(), grid[0].size()) && !seen[r][c]) {
                ans = min(ans, solve(grid, seen, r, c, last) + temp);
            }
        }
        seen[i][j] = false;
        return ans;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> seen(n, vector<bool>(m, false));
        return solve(grid, seen, 0, 0, 0);
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> grid[i][j];
    }

    cout << (new Solution())->swimInWater(grid);
}