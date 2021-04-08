#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> v1, vector<int> v2) {
}

int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), compare);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tasks(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> tasks[i][0] >> tasks[i][1];
    }
    cout << minimumEffort(tasks);
    return 0;
}