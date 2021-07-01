#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long D, d, p, q;
        long ans = 0;
        cin >> D >> d >> p >> q;

        long x = (D - 1) / d;

        ans = (D * p) + (q * d * ((x * (x + 1)) / 2)) + (D - (x + 1) * d) * (q * x);
        cout << ans << endl;
    }
}
