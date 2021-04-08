#include <bits/stdc++.h>
using namespace std;

//  Fail

int getLeftMax(vector<vector<int>>& height, int row, int col) {
    int mVal = 0;
    while (col >= 0) {
        mVal = max(mVal, height[row][col]);
        col--;
    }
    return mVal;
}

int getRightMax(vector<vector<int>>& height, int row, int col) {
    int mVal = 0, n = height[row].size();
    while (col < n) {
        mVal = max(mVal, height[row][col]);
        col++;
    }
    return mVal;
}

int getTopMax(vector<vector<int>>& height, int row, int col) {
    int mVal = 0;
    while (row >= 0) {
        mVal = max(mVal, height[row][col]);
        row--;
    }
    return mVal;
}

int getBottomMax(vector<vector<int>>& height, int row, int col) {
    int mVal = 0, n = height.size();
    while (row < n) {
        mVal = max(mVal, height[row][col]);
        row++;
    }
    return mVal;
}

int trapRainWater(vector<vector<int>>& height) {
    int n = height.size(), m = height[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int leftMax = getLeftMax(height, i, j - 1);
            int rightMax = getRightMax(height, i, j + 1);
            int topMax = getTopMax(height, i - 1, j);
            int bottomMax = getBottomMax(height, i + 1, j);

            int temp = min({leftMax, rightMax, topMax, bottomMax});
            if ((temp - height[i][j]) > 0) {
                ans += (temp - height[i][j]);
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