#include <bits/stdc++.h>
using namespace std;

class Solution {
#define pair pair<int, pair<int, int>>
   public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        priority_queue<pair, vector<pair>, greater<pair>> minPq;
        for (int i = 0; i < n; i++) minPq.push({mat[i][0], {i, 0}});
        while (minPq.size()) {
            pair temp = minPq.top();
            minPq.pop();
            if (temp.first == target) return true;
            int x = temp.second.first, y = temp.second.second;
            if (y + 1 < m && mat[x][y + 1] <= target) minPq.push({mat[x][y + 1], {x, y + 1}});
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size(), r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (mat[r][c] == target) {
                return true;
            }
            if (mat[r][c] < target) {
                r++;
            } else {
                c--;
            }
        }
        return true;
    }
};

int main() {
    int n, t;
    cin >> n >> t;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> mat[i][j];
    }
    cout << (new Solution())->searchMatrix(mat, t);
    return 0;
}