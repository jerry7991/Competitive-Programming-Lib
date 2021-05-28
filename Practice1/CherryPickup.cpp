#include <bits/stdc++.h>
using namespace std;

vector<int> dirx = {0, 1};
vector<int> diry = {1, 0};

int infinity = -50 * 50 - 1;

int getMaxCherry(vector<vector<int>>& grid, int endI, int endJ, int startI, int startJ) {
    if (startI > grid.size() || min(startI, startJ) < 0 || startJ > grid[0].size()) {
        return infinity;
    }

    if (startI == endI && startJ == endJ) {
        return grid[startI][startJ];
    }

    if (grid[startI][startJ] < 0) {
        return infinity;
    }

    int ans = infinity;
    for (int i = 0; i < 2; i++) {
        ans = max(ans, getMaxCherry(grid, endI, endJ, startI + dirx[i], startJ + diry[i]));
    }
    return ans;
}

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    int topDown = getMaxCherry(grid, n - 1, m - 1, 0, 0);
    return topDown;
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

    cout << cherryPickup(grid);
}