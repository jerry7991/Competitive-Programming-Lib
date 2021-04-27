// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void getThePermutation(int curr, vector<vector<int>>& permutation, vector<int>& temp) {
    if (curr == temp.size()) {
        permutation.push_back(temp);
        return;
    }
    for (int i = curr; i < temp.size(); i++) {
        swap(temp[curr], temp[i]);
        getThePermutation(curr + 1, permutation, temp);
        swap(temp[curr], temp[i]);
    }
}

int countArrangement(int n) {
    vector<int> temp(n);

    for (int i = 1; i <= n; i++) {
        temp[i - 1] = i;
    }

    vector<vector<int>> permutation;
    getThePermutation(0, permutation, temp);

    int count = 0;
    for (int i = 0; i < permutation.size(); i++) {
        bool flag = true;
        for (int j = 0; j < permutation[i].size(); j++) {
            // cout<<permutation[i][j] <<" ";
            flag &= ((permutation[i][j] % (j + 1) == 0) || ((j + 1) % permutation[i][j]) == 0);
        }
        // cout<<endl;
        count += flag;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countArrangement(n);
}