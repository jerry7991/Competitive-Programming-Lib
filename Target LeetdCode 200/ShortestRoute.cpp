#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, maxVal = 1e9;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);

    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (i == 0)
            mp[i] = 0;
        else if (nums1[i] != 0)
            mp[i] = 0;
        else
            mp[i] = maxVal;
    }
    int r = -1, l = -1;
    for (int i = 0; i < n; i++) {
        if (nums1[i] == 1) r = i;
        if (r != -1) {
            if (nums1[i] == 0)
                mp[i] = min(mp[i], i - r);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (nums1[i] == 2) l = i;
        if (l != -1) {
            if (nums1[i] == 0)
                mp[i] = min(mp[i], l - i);
        }
    }
    for (int i = 0; i < m; i++) {
        int j = nums2[i] - 1;
        if (mp[j] != maxVal)
            cout << mp[j] << " ";
        else
            cout << -1 << " ";
    }
    cout << '\n';
}

int32_t main() {
    int n;
    cin >> n;
    while (n--) solve();
}