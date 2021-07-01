#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> seen(51, vector<bool>(51, false));

class Solution {
   public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool isValid(int i, int j, int n) {
        return min(i, j) >= 0 && max(i, j) < n && !seen[i][j];
    }

    bool isPossible(vector<vector<int>>& grid, int i, int j, int w, int last = 0) {
        w -= (last >= grid[i][j]) ? 0 : (grid[i][j] - last);
        if (w < 0) return false;
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return w >= 0;
        }
        seen[i][j] = true;
        last = max(last, grid[i][j]);
        bool flag = false;
        for (int k = 0; k < 4 && !flag; k++) {
            int r = i + dx[k], c = j + dy[k];
            if (isValid(r, c, grid.size()) && isPossible(grid, r, c, w, last)) {
                flag = true;
            }
        }
        return flag;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int l = 0, r = n * n, ans = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (isPossible(grid, 0, 0, m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
            for (int i = 0; i < 51; i++)
                for (int j = 0; j < 51; j++) seen[i][j] = false;
        }
        return ans;
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