#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long getThePowerMode(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res % mod;
}

void solve() {
    long long n, m;
    cin >> n >> m;
    long long num = getThePowerMode(2, n) - 1;

    cout << getThePowerMode(num, m) << endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
