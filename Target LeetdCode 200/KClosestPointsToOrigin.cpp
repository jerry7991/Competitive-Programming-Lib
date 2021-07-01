#include <bits/stdc++.h>

#define pair pair<double, pair<int, int>>

using namespace std;

class Solution {
   public:
    double getDistance(int x, int y) {
        return sqrt(x * x + y * y);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair, vector<pair>, greater<pair>> minPq;
        for (auto x : points) {
            minPq.push({getDistance(x[0], x[1]), {x[0], x[1]}});
        }
        vector<vector<int>> out;
        for (int i = 0; i < k; i++) {
            auto x = minPq.top();
            minPq.pop();
            out.push_back({x.second.first, x.second.second});
        }
        return out;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> points[i][0] >> points[i][1];

    auto x = (new Solution())->kClosest(points, k);
    for (auto y : x)
        for (auto z : y) cout << z << " ";
}