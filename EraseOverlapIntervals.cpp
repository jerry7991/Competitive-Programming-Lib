#include <bits/stdc++.h>
using namespace std;

static bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    int last = -1, curr = 0, skip = 0;
    while (curr < intervals.size()) {
        if (last < 0 || intervals[curr][0] >= intervals[last][1]) {
            last = curr;
        } else {
            skip++;
        }
        curr++;
    }
    return skip;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> intervals[i][0] >> intervals[i][1];
    cout << eraseOverlapIntervals(intervals);
}