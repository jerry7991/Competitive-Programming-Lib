#include <bits/stdc++.h>
using namespace std;

bool canReachBfs(vector<int>& arr, int start) {
    int n = arr.size(), m;
    queue<int> q;
    vector<bool> vis(n, false);
    q.push(start);

    while (m = q.size()) {
        while (m--) {
            int tmp = q.front();
            q.pop();
            if (arr[tmp] == 0) return true;
            vis[tmp] = true;
            int left = tmp - arr[tmp], right = tmp + arr[tmp];
            if (left >= 0 && !vis[left]) q.push(left);

            if (right < n && !vis[right]) q.push(right);
        }
    }
    return false;
}

bool canReach(vector<int>& arr, int start) {
    if (start < 0 || start > arr.size()) {
        return false;
    }

    if (arr[start] == 0) {
        return true;
    }

    bool leftSide = canReach(arr, start + arr[start]);
    bool rightSide = canReach(arr, start - arr[start]);
    return (leftSide || rightSide);
}

int main() {
    int n;
    cin >> n;

    vector<int> num(n);
    int start;

    for (int i = 0; i < n; i++) cin >> num[i];

    cin >> start;
    cout << canReach(num, start);
}