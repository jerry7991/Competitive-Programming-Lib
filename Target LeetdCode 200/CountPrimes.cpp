#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    vector<bool> v(n, false);

    int count = 0;
    for (long i = 2; i * i < n; i++) {
        if (v[i]) continue;
        for (long j = i * i; j < n; j += i) {
            v[j] = true;
        }
    }

    for (int i = 2; i < n; i++) {
        if (!v[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countPrimes(n);
}