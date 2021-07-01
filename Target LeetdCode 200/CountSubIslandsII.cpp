#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool isValid(int i, int j, vector<vector<int>>& grid2) {
        return (min(i, j) >= 0 && i < grid2.size() && j < grid2[0].size() && grid2[i][j]);
    }

    void doDfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int& flag) {
        if (!grid1[i][j]) {
            // Not a valid island, need to revert our assumption
            flag = 0;
            return;
        }

        //  Mark visited
        grid2[i][j] = 0;

        //  Explore all possible path
        for (int k = 0; k < 4; k++) {
            int r = i + dx[k], c = j + dy[k];
            if (isValid(r, c, grid2)) {
                doDfs(grid1, grid2, r, c, flag);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size(), count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j]) {
                    //  Let's assume we are getting a valid island
                    int isAllConnect = 1;
                    doDfs(grid1, grid2, i, j, isAllConnect);
                    count += isAllConnect;
                }
            }
        }
        return count;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid1(n, vector<int>(m)), grid2(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> grid1[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> grid2[i][j];
    }

    cout << (new Solution())->countSubIslands(grid1, grid2);
}