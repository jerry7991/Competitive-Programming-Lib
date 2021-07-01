#include <bits/stdc++.h>
#define pair pair<int, pair<int, int>>

using namespace std;

vector<vector<bool>> seen(51, vector<bool>(51, false));

class Solution {
   public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool isValid(int i, int j, int n) {
        return min(i, j) >= 0 && max(i, j) < n && !seen[i][j];
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;

        priority_queue<pair, vector<pair>, greater<pair>> minPq;

        minPq.push({grid[0][0], {0, 0}});

        while (minPq.size()) {
            auto x = minPq.top();
            minPq.pop();
            res = max(res, x.first);
            int r = x.second.first, c = x.second.second;
            if (r == n - 1 && c == n - 1) return res;
            seen[r][c] = true;
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if (isValid(nr, nc, n)) {
                    minPq.push({grid[nr][nc], {nr, nc}});
                }
            }
        }
        return res;
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