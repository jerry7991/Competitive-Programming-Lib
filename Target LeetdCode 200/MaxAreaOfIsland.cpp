#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};

    bool inRange(vector<vector<int>>& grid, int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m && grid[i][j]);
    }

    int solve(vector<vector<int>>& grid, int i, int j) {
        int ans = 0;
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            if (inRange(grid, i + dx[k], j + dy[k], grid.size(), grid[0].size())) {
                ans = ans + 1 + solve(grid, i + dx[k], j + dy[k]);
            }
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    ans = max(ans, solve(grid, i, j) + 1);
                }
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];
    cout << (new Solution())->maxAreaOfIsland(grid);
}