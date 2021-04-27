#include <bits/stdc++.h>
using namespace std;

int countTriplets(vector<int>& arr) {
    int n = arr.size(), count = 0;
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        for (int j = i + 1; j < n; j++) {
            x ^= arr[j];
            if (x == 0) count += (j - i);
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << countTriplets(v);
}