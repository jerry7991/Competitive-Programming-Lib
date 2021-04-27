#include <bits/stdc++.h>
using namespace std;

int findMinFibonacciNumbers(int k) {
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);
    int n = 1, i = 2;

    while (n < k) {
        n = fib[i - 1] + fib[i - 2];
        fib.push_back(n);
        i++;
    }

    i = fib.size() - 1;

    int count = 0;
    while (k > 0) {
        if (fib[i] <= k) {
            k - fib[i];
            count++;
        } else {
            i--;
        }
    }
    return count;
}

int main() {
    int k;
    cin >> k;
    cout << findMinFibonacciNumbers(k);
}