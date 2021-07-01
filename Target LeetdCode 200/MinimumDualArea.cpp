#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> numsX(n), numsY(n);
    multiset<int> mstX, mstY;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        numsX[i] = {x, y};
        numsY[i] = {y, x};
        mstX.insert(x);
        mstY.insert(y);
    }
    sort(numsX.begin(), numsX.end());
    sort(numsY.begin(), numsY.end());

    int h1 = 0, h2 = 0, h1Max = 0, h1Min = LONG_MAX, area = LONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        h1Max = max(h1Max, numsX[i].second);
        h1Min = min(h1Min, numsX[i].second);
        h1 = h1Max - h1Min;
        auto it = mstY.find(numsX[i].second);
        mstY.erase(it);

        h2 = *mstY.rbegin() - *mstY.begin();
        int newAreaa = (numsX[i].first - numsX[0].first) * h1 + (numsX[n - 1].first - numsX[i + 1].first) * h2;
        area = min(area, newAreaa);
    }
    int w1 = 0, w2 = 0, w1Max = 0, w1Min = LONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        w1Max = max(w1Max, numsY[i].second);
        w1Min = min(w1Min, numsY[i].second);
        w1 = w1Max - w1Min;
        auto it = mstX.find(numsY[i].second);
        mstX.erase(it);
        w2 = *mstX.rbegin() - *mstX.begin();

        int newAreaa = (numsY[i].first - numsY[0].first) * w1 + (numsY[n - 1].first - numsY[i + 1].first) * w2;
        area = min(area, newAreaa);
    }

    if (area == LONG_MAX) {
        area = 0;
    }
    cout << area << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}