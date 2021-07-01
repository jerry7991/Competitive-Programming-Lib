#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> visited(500, vector<bool>(500, false));

class Solution {
   public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool isValid(int i, int j, vector<vector<int>>& grid2) {
        return (min(i, j) >= 0 && i < grid2.size() && j < grid2[0].size() && grid2[i][j]);
    }

    bool isCommonPath(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if (grid1[i][j] == 0) {
            // This is not a valid island. We need to reset.
            return false;
        }
        // Mark as visited
        visited[i][j] = true;

        bool flag = true;
        for (int k = 0; k < 4 && flag; k++) {
            int r = i + dx[k], c = j + dy[k];
            if (isValid(r, c, grid2) && !visited[i][j] && !isCommonPath(grid1, grid2, r, c)) {
                flag = false;
            }
        }
        return flag;
    }

    void reset(vector<vector<int>>& grid2, int i, int j) {
        grid2[i][j] = 0;

        //  Explore all the possible way and reset them also
        for (int k = 0; k < 4; k++) {
            int r = i + dx[k], c = j + dy[k];
            if (isValid(r, c, grid2)) {
                reset(grid2, r, c);
            }
        }
    }

    void doDfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            int r = i + dx[k], c = j + dy[k];
            if (isValid(r, c, grid)) {
                doDfs(grid, r, c);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size(), count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j]) {
                    //  Check all possible path grid1 contains or not
                    if (!isCommonPath(grid1, grid2, i, j)) {
                        // If not the reset it.
                        reset(grid2, i, j);
                    }
                }
            }
        }

        // Count number of connected components
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j]) {
                    count++;
                    doDfs(grid2, i, j);
                }
            }
        }
        return count;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid1(n, vector<int>(m)), grid2(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> grid1[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> grid2[i][j];
    }

    cout << (new Solution())->countSubIslands(grid1, grid2);
}