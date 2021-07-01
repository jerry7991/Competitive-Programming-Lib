#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    bool isValid(int i, int j, int n, int m) {
        return !(i < 0 || j < 0 || i >= n || j >= m);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> weight(n, vector<int>(m, INT_MAX));
        weight[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minPq;
        minPq.push({0, {0, 0}});

        while (minPq.size()) {
            auto curr = minPq.top();
            minPq.pop();
            int x = curr.second.first, y = curr.second.second, dist = curr.first;
            if (x == n - 1 && y == m - 1) return dist;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (!isValid(nx, ny, n, m)) continue;

                int newDist = max(dist, abs(heights[x][y] - heights[nx][ny]));

                if (newDist < weight[nx][ny]) {
                    weight[nx][ny] = newDist;
                    minPq.push({newDist, {nx, ny}});
                }
            }
        }
        return 0;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> heights(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> heights[i][j];
    }
    cout << (new Solution())->minimumEffortPath(heights);
}