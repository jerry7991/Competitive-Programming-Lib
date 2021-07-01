#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isValid(int i, int j, int n, int m, vector<vector<bool>>& seen) {
        return min(i, j) >= 0 && i < n && j < m && !seen[i][j];
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), d = 0;
        vector<vector<bool>> seen(n, vector<bool>(m));
        queue<pair<int, int>> level;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0)
                    level.push({i, j}), seen[i][j] = true;
                else
                    mat[i][j] = (n * m);
            }
        }
        while (level.size()) {
            int l = level.size();
            d++;
            while (l--) {
                pair<int, int> x = level.front();
                level.pop();
                for (int i = 0; i < 4; i++) {
                    int newI = x.first + dx[i];
                    int newJ = x.second + dy[i];
                    if (isValid(newI, newJ, n, m, seen)) {
                        mat[newI][newJ] = min(mat[newI][newJ], d);
                        level.push({newI, newJ});
                        seen[newI][newJ] = true;
                    }
                }
            }
        }
        return mat;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> mat[i][j];
    auto x = (new Solution())->updateMatrix(mat);
    for (auto y : x) {
        for (auto z : y) cout << z << " ";
        cout << endl;
    }
}