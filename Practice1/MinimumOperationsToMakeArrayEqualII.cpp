#include <bits/stdc++.h>
using namespace std;

/*
    O(1) Time and O(1) space
*/

int minOperations(int n) {
    int N;
    if (n & 1) {
        N = (n - 1) / 2;
        return N * (N + 1);
    }
    N = n / 2;
    return N * N;
}

int main() {
    int n;
    cin >> n;
    cout << minOperations(n) << endl;
}