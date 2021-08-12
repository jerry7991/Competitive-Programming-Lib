#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    int point = 1;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == n) {
            for (int j = 1; j <= n; j++) cout << point << " ";
        } else {
            for (int j = 1; j <= n; j++) {
                if (j == 1 || j == n) {
                    cout << point << " ";
                } else {
                    cout << "  ";
                }
            }
        }
        point += 2;
        point %= 10;
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    solve(n);
}