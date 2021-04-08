#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& row) {
    int n = row.size(), ans = 0;
    stack<int> st;
    for (int i = 0; i <= n; i++) {
        int hd = (i == n) ? 0 : row[i];

        if (st.empty() || hd >= row[st.top()]) {
            st.push(i);
        } else {
            int id = st.top();
            st.pop();
            ans = max(ans, row[id] * ((st.empty()) ? i : (i - 1 - st.top())));
            i--;
        }
    }
    return ans;
}

void reset(vector<int>& row, vector<vector<char>>& matrix, int j) {
    for (int i = 0; i < matrix[0].size(); i++) {
        row[i] = (matrix[j][i] == '0') ? 0 : (row[i] + 1);
    }
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int n, m;
    if ((n = matrix.size()) && (m = matrix[0].size())) {
        // return 0;
    } else {
        return 0;
    }
    int ans = 0;
    vector<int> row(m);
    for (int i = 0; i < m; i++) row[i] = (matrix[0][i] == '1');
    ans = largestRectangleArea(row);
    for (int i = 1; i < n; i++) {
        reset(row, matrix, i);
        ans = max(ans, largestRectangleArea(row));
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> matrix[i][j];
    }
    cout << maximalRectangle(matrix);
}