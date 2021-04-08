#include <bits/stdc++.h>
using namespace std;

int getRowIndex(int i, int j, int n, int m) {
    return i * m + j;
}

int minFlips(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    string key = "";
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            key.append(to_string(mat[i][j]));
        }
    }

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    queue<string> level;
    unordered_map<string, int> vist;
    vist[key] = 1;
    level.push(key);
    while (level.size()) {
        key = level.front();
        level.pop();

        bool found = true;

        for (char ch : key) {
            found &= (ch != '1');
        }
        if (found) {
            return vist[key] - 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int rIdx = getRowIndex(i, j, n, m);
                string currKey = key;

                currKey[rIdx] = (currKey[rIdx] == '0') ? '1' : '0';

                for (int k = 0; k < 4; k++) {
                    int newRow = i + dx[k];
                    int newCol = j + dy[k];
                    if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m) {
                        int mIdx = getRowIndex(newRow, newCol, n, m);

                        currKey[mIdx] = (currKey[mIdx] == '0') ? '1' : '0';
                    }
                }

                if (!vist[currKey]) {
                    vist[currKey] = 1 + vist[key];
                    level.push(currKey);
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    cout << minFlips(mat) << endl;
}
