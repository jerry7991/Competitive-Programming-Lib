#include <bits/stdc++.h>
using namespace std;

bool Compare(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

double dist(vector<int>& a, vector<int>& b) {
    return sqrt(pow(b[0] - a[0], 2) + pow(b[1] - a[1], 2));
}

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    vector<vector<int>> all;
    all.push_back(p1);
    all.push_back(p2);
    all.push_back(p3);
    all.push_back(p4);
    sort(begin(all), end(all), Compare);
    int i = 0, j = 2;

    bool ans = (dist(all[0], all[1]) != 0) && (dist(all[0], all[1]) == dist(all[1], all[3])) && (dist(all[3], all[2]) == dist(all[1], all[3]) && (dist(all[3], all[2]) == dist(all[1], all[0]) && (dist(all[0], all[3]) == dist(all[1], all[2]))));

    return ans;
}

int main() {
}