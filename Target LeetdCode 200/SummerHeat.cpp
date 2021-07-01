#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int xa, xb, XA, XB;
        cin >> xa >> xb >> XA >> XB;
        int x = XA / xa, y = XB / xb;
        cout << (min(x, y) + abs(x - y)) << endl;
    }
}