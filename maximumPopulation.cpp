#include <bits/stdc++.h>
using namespace std;

int maximumPopulation(vector<vector<int>>& logs) {
    int n = logs.size(), totalCount = 0, year = 1950;

    for (int i = year; i < 2051; i++) {
        int curr = 0;
        for (int j = 0; j < n; j++) {
            if (logs[j][0] <= i && logs[j][1] > i) {
                curr++;
            }
        }
        if (curr > totalCount) {
            totalCount = curr;
            year = i;
        }
    }

    return year;
}

int main() {
}