// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void getThePermutation(int curr, vector<int>& temp, int& count) {
    if (curr == temp.size()) {
        count++;

        return;
    }
    for (int i = curr; i < temp.size(); i++) {
        swap(temp[curr], temp[i]);

        if ((temp[curr] % (curr) == 0) || ((curr) % temp[curr] == 0)) {
            getThePermutation(curr + 1, temp, count);
        }

        swap(temp[curr], temp[i]);
    }
}

int countArrangement(int n) {
    vector<int> temp(n + 1);

    for (int i = 1; i <= n; i++) {
        temp[i] = i;
    }
    int count = 0;

    getThePermutation(1, temp, count);
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countArrangement(n);
}