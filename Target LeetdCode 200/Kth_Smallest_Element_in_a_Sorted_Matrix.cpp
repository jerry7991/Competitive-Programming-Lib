#include <bits/stdc++.h>
#define pair pair<int, pair<int, int>>
using namespace std;

class Solution {
   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair, vector<pair>, greater<pair>> minPq;
        for (int i = 0; i < n; i++) {
            minPq.push({matrix[i][0], {i, 0}});
        }

        while (k--) {
            pair temp = minPq.top();
            minPq.pop();
            int x = temp.second.first, y = temp.second.second;
            if (y + 1 < n) {
                minPq.push({matrix[x][y + 1], {x, y + 1}});
            }
        }
        return minPq.top().first;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> mat[i][j];
    }
    cout << (new Solution())->kthSmallest(mat, k);
}