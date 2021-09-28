class Solution {
  public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long res = LLONG_MAX, bottomSum = 0;

        for (int i = 0; i < grid[0].size(); i++) {
            topSum -= grid[0][i];
            res = min(res, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }
        return res;
    }
};