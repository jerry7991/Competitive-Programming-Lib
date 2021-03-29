#include<bits/stdc++.h>
using namespace std;
#define n 10

void resetHorizontal(char grid[n][n], vector<string> &list, int index, int row, int col, vector<bool> helper) {
    for (unsigned int i = 0; i < list[index].size(); i++) {
        if (helper[i]) {
            // if helper is true that's means we have to reset
            grid[row][i + col] = '-';
        }
    }
}

void setHorizontal(char grid[n][n], vector<string> &list, int index, int row, int col, vector<bool> &helper) {
    for (int i = 0; i < list[index].size(); i++) {
        if (grid[row][i + col] == '-') {
            grid[row][i + col] = list[index][i];
            helper[i] = true;
        } else {
            helper[i] = false;
        }
    }
}

void resetVertical(char grid[n][n], vector<string> &list, int index, int row, int col, vector<bool> helper) {
    for (int i = 0; i < list[index].size(); i++) {
        if (helper[i]) {
            grid[i + row][col] = '-';
        }
    }
}

void setVertical(char grid[n][n], vector<string> &list, int index, int row, int col, vector<bool> &helper) {
    for (int i = 0; i < list[index].size(); i++) {
        if (grid[i + row][col] == '-') {
            grid[i + row][col] = list[index][i];
            helper[i] = true;
        } else {
            helper[i] = false;
        }
    }
}

bool isHorizontal(char grid[n][n], vector<string> &list, int index, int row, int col, int length) {
    if (length == list[index].size()) {
        return true;
    }

    if (grid[row][col] == '-' || grid[row][col] == list[index][length]) {
        return isHorizontal(grid, list, index, row, col + 1, length + 1);
    } else {
        return false;
    }
}

bool isVertical(char grid[n][n], vector<string> &list, int index, int row, int col, int length) {
    if (length == list[index].size()) {
        return true;
    }

    if (grid[row][col] == '-' || grid[row][col] == list[index][length]) {
        return isVertical(grid, list, index, row + 1, col, length + 1);
    } else {
        return false;
    }
}

bool crossword(char grid[n][n], vector<string> list, int index) {
    if (index == list.size()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        return true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '-' || grid[i][j] == list[index][0]) {
                if (isVertical(grid, list, index, i, j, 0)) {
                    vector<bool> helper(list[index].size());
                    setVertical(grid, list, index, i, j, helper);
                    if (crossword(grid, list, index + 1)) {
                        return true;
                    }
                    resetVertical(grid, list, index, i, j, helper);
                }
                if (isHorizontal(grid, list, index, i, j, 0)) {
                    vector<bool> helper(list[index].size());
                    setHorizontal(grid, list, index, i, j, helper);
                    if (crossword(grid, list, index + 1)) {
                        return true;
                    }
                    resetHorizontal(grid, list, index, i, j, helper);
                }
            }
        }
    }
    return false;
}

int main() {
    // handling input
    char grid[n][n];
    for (int i = 0; i < n; i++) {
        string s;   cin >> s;
        for (int j = 0; j < s.length(); j++) {
            grid[i][j] = s[j];
        }
    }

    vector<string> list;
    string s;   cin >> s;
    // s += ';';
    s.push_back(';');
    string temp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ';') {
            list.push_back(temp);
            temp = "";
            continue;
        }
        temp += s[i];
    }

    // for(auto x: list ) cout<<x<<endl;

    // handling crossword
    crossword(grid, list, 0);


    // for(int i = 0; i < n; i++) {
    //      for(int j = 0; j < n; j++) {
    //          cout << grid[i][j];
    //      }
    //         cout << endl;
    //  }
}