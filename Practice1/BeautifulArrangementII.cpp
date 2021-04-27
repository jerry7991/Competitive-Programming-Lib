#include <bits/stdc++.h>
using namespace std;

vector<int> constructArray(int n, int k) {
    vector<int> ans(n);
    int c = 0;
    for (int i = 1; i < n - k; i++) {
        ans[c++] = i;
    }

    for (int i = 0; i <= k; i++) {
        ans[c++] = (i % 2 == 0) ? (n - k + i / 2) : (n - i / 2);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> out = constructArray(n, k);
    for (int i : out) cout << i << " ";
}