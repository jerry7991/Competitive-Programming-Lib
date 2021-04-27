#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& v) {
    int ans = INT_MIN;
    int n = v.size();
    int curr = 0;
    vector<int> suffix(n);

    suffix[n - 1] = v[n - 1];
    for (int i = 0; i < n; i++) {
        curr += v[i % n];
        ans = max(ans, curr);
        curr = max(0, curr);

        // make suffix
        if (i) {
            suffix[n - i - 1] = suffix[n - i] + v[n - i - 1];
        }
    }

    //  Make maximum suffix sum
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = max(suffix[i + 1], suffix[i]);
    }

    int left = 0;
    for (int i = 0; i < n - 1; i++) {
        left += v[i];
        // Include left+ bestSuffix till i or kadanes answer
        ans = max(ans, left + suffix[i + 1]);
    }

    return ans;
}

int maxSubarraySumCircularDqueue(vector<int>& v) {
    int n = v.size(), ans = INT_MIN;
    deque<int> dq;

    //  Store all the sum
    vector<int> sum(2 * n + 1);
    sum[0] = 0;
    for (int i = 0; i < 2 * n; i++) {
        sum[i + 1] = sum[i] + v[i % n];
    }

    dq.push_back(0);
    ans = v[0];

    for (int i = 1; i <= 2 * n; i++) {
        // Trim the de-queue for size N
        while (dq.size() && (dq.front()) < (i - n)) {
            dq.pop_front();
        }

        ans = max(ans, sum[i] - sum[dq.front()]);

        // Trim the deque (sum[dq.back()] >= sum[i]) Means we got some -ve number which decreased the sum
        while (dq.size() && sum[dq.back()] >= sum[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << maxSubarraySumCircular(v);
}