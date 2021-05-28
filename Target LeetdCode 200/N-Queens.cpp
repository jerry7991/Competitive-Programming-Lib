#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    vector<vector<string>> out;
    vector<string> board;
    bool isValidVertical(int row, int col) {
        while (row >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
        }
        return true;
    }

    bool isValidDiagonal(int row, int col) {
        int i = row, j = col;

        while (i >= 0 && j < board.size()) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }

        i = row, j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }

    bool isValid(int row, int col) {
        return isValidVertical(row, col) && isValidDiagonal(row, col);
    }

   public:
    void solve(int row, int n) {
        if (row == n) {
            out.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isValid(row, i)) {
                board[row][i] = 'Q';
                solve(row + 1, n);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string str = "";
        for (int i = 0; i < n; i++) str.push_back('.');
        for (int i = 0; i < n; i++) board.push_back(str);
        solve(0, n);
        return out;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<string>> out = (new Solution())->solveNQueens(n);
    for (auto x : out) {
        for (auto y : x) cout << y << endl;
        cout << endl;
    }
}
