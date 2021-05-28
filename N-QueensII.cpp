#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    int count = 0;
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
            count++;
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

    int totalNQueens(int n) {
        string str = "";
        for (int i = 0; i < n; i++) str.push_back('.');
        for (int i = 0; i < n; i++) board.push_back(str);
        solve(0, n);
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    int out = (new Solution())->totalNQueens(n);
    cout << out << endl;
}