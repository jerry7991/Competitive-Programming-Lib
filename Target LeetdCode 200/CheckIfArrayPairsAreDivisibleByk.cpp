#include <bits/stdc++.h>
using namespace std;

bool canArrange(vector<int>& arr, int k) {
    vector<int> freq(k + 1, 0);
    for (int x : arr) {
        freq[(x % k + k) % k]++;
    }

    for (int i = 0; i < k; i++) {
        if (i == 0 || i == k - i) {
            if (freq[i] % 2) return false;
            continue;
        }
        if (freq[i] != freq[k - i]) return false;
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << canArrange(arr, k);
}