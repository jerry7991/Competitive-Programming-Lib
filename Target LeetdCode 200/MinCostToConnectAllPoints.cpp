#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int n = ps.size(), res = 0, i = 0, connected = 0;
        vector<bool> visited(n);
        priority_queue<pair<int, int>> pq;
        while (++connected < n) {
            visited[i] = true;
            for (int j = 0; j < n; ++j)
                if (!visited[j])
                    pq.push({-(abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1])), j});
            while (visited[pq.top().second])
                pq.pop();
            res -= pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++) cin >> points[i][j];
    cout << (new Solution())->minCostConnectPoints(points);
}