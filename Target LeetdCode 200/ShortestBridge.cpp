#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    void doDfs(vector<vector<int>>& grid, int r, int c) {
        grid[r][c] = 2;
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if (min(nr, nc) >= 0 && nr < grid.size() && nc < grid[nr].size() && grid[nr][nc] == 1) {
                doDfs(grid, nr, nc);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        bool flag = true;
        queue<pair<int, pair<int, int>>> level;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (flag) {
                        flag = !flag;
                        doDfs(grid, i, j);
                    } else {
                        level.push({0, {i, j}});
                    }
                }
            }
        }

        while (level.size()) {
            int l = level.size();
            while (l--) {
                auto y = level.front();
                level.pop();
                auto x = y.second;
                grid[x.first][x.second] = -1;
                for (int i = 0; i < 4; i++) {
                    int r = x.first + dx[i], c = x.second + dy[i];
                    if (min(r, c) >= 0 && r < grid.size() && c < grid[r].size() && (grid[r][c] == 0 || grid[r][c] == 2)) {
                        if (grid[r][c] == 2) return y.first;
                        grid[r][c] = -1;
                        level.push({y.first + 1, {r, c}});
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> mat[i][j];
    int x = (new Solution())->shortestBridge(mat);
    cout << x << endl;
}