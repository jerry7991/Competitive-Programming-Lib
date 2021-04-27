#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void dfs(vector<vector<char>>& board, int row, int col) {
    if (min(row, col) < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != 'O') {
        return;
    }
    board[row][col] = '$';
    for (int i = 0; i < 4; i++) {
        dfs(board, row + dx[i], col + dy[i]);
    }
}

void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++) {
        if (board[i][0] == 'O') {
            dfs(board, i, 0);
        }
        if (board[i][m - 1] == 'O') {
            dfs(board, i, m - 1);
        }
    }

    for (int j = 0; j < m; j++) {
        if (board[0][j] == 'O') {
            dfs(board, 0, j);
        }
        if (board[n - 1][j] == 'O') {
            dfs(board, n - 1, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '$') {
                board[i][j] = 'O';
            } else {
                board[i][j] = 'X';
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    solve(board);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}