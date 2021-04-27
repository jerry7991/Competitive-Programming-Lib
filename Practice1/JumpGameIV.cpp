#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int>& arr) {
    int n = arr.size(), l;
    unordered_map<int, vector<int>> index;
    for (int i = 0; i < n; i++) {
        index[arr[i]].push_back(i);
    }

    vector<bool> vis(n, false);

    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0] = true;
    while (l = q.size()) {
        while (l--) {
            pair tmp = q.front();
            q.pop();
            if (tmp.first == n - 1) return tmp.second;

            if (tmp.first - 1 >= 0 && !vis[tmp.first - 1]) {
                q.push({tmp.first - 1, tmp.second + 1});
                vis[tmp.first - 1] = true;
            }

            if (tmp.first + 1 < n && !vis[tmp.first + 1]) {
                q.push({tmp.first + 1, tmp.second + 1});
                vis[tmp.first + 1] = true;
            }

            for (int i : index[arr[tmp.first]]) {
                if (!vis[i] && tmp.first != i) {
                    vis[i] = true;
                    q.push({i, tmp.second + 1});
                }
            }
            index[arr[tmp.first]].clear();
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> num(n);

    for (int i = 0; i < n; i++) cin >> num[i];

    cout << minJumps(num);
}