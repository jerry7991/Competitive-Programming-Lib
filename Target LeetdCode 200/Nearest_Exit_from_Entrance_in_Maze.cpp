#include <bits/stdc++.h>
using namespace std;

class Data {
   public:
    int i, j, level;
    Data(int i, int j, int level) {
        this->i = i;
        this->j = j;
        this->level = level;
    }
};

class Solution {
   public:
    bool isValid(int i, int j, int r, int c, vector<vector<char>>& maze) {
        return i >= 0 && j >= 0 && i < r && j < c && maze[i][j] != '+';
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size(), c = maze[0].size();

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        queue<Data*> q;
        q.push(new Data(entrance[0], entrance[1], 0));
        maze[entrance[0]][entrance[1]] = '+';

        while (q.size()) {
            int n = q.size();
            while (n--) {
                Data* data = q.front();
                q.pop();
                if ((data->i != entrance[0] || data->j != entrance[1]) && (min(data->i, data->j) == 0 || data->i == r - 1 || data->j == c - 1)) {
                    return data->level;
                }

                for (int i = 0; i < 4; i++) {
                    int nr = data->i + dx[i], nc = data->j + dy[i];
                    if (isValid(nr, nc, r, c, maze)) {
                        maze[nr][nc] = '+';
                        q.push(new Data(nr, nc, data->level + 1));
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
}