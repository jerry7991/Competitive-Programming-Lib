#include <bits/stdc++.h>
using namespace std;


class Solution {
    vector<bool> blocked;
    unordered_map<int, int> dp;
    const int imp = 1e6;

public:
    Solution() {
        blocked.resize(6000);
    }

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for (int x : forbidden) blocked[x] = true;
        queue<pair<int, int>> level;
        level.push({0,  0});
        vector<vector<bool>> seen(6000, vector<bool>(2, false)); // 0 ->forward and 1 for backward
        int step = 0, farthest = 6000;
        seen[0][0] = seen[0][1] = true;

        while (level.size()) {
            int n = level.size();
            while (n--) {
                pair<int, int> temp = level.front(); level.pop();
                int lastBack = temp.second;
                int u = temp.first;

                if (u == x) return step;

                int v = u + a;
                if (v < farthest && !seen[v][1] && !blocked[v]) {
                    seen[v][1] = true;
                    level.push({v, 0});
                }
                v = u - b;
                if (v >= 0 && !seen[v][0] && !lastBack && !blocked[v]) {
                    seen[v][0] = true;
                    level.push({v,  1});
                }
            }
            step++;
        }
        return -1;
    }
};