#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<int>>& height, int x, int y) {
    int n = height.size(), m = height[0].size();
    return (x >= 0 && y >= 0 && x < n && y < m && height[x][y] >= 0);
}
class customComparator {
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        return a.first > b.first;
    }
};

int trapRainWater(vector<vector<int>>& height) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int n = height.size(), m = height[0].size();
    for (int i = 0; i < n; i++) {
        pq.push({height[i][0], {i, 0}});
        pq.push({height[i][m - 1], {i, m - 1}});
        height[i][0] = height[i][m - 1] = -1;
    }
    for (int i = 1; i < m - 1; i++) {
        pq.push({height[0][i], {0, i}});
        pq.push({height[n - 1][i], {n - 1, i}});
        height[0][i] = height[n - 1][i] = -1;
    }

    int ans = 0, maxTillNow = INT_MIN;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (pq.size()) {
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();
        int h = temp.first, x = temp.second.first, y = temp.second.second;
        // height[x][y] = -1;

        maxTillNow = max(maxTillNow, h);
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isValid(height, newX, newY)) {
                pq.push({height[newX][newY], {newX, newY}});
                if (height[newX][newY] < maxTillNow) {
                    ans += (maxTillNow - height[newX][newY]);
                }
                height[newX][newY] = -1;
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> height(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> height[i][j];
    }
    cout << trapRainWater(height);
}