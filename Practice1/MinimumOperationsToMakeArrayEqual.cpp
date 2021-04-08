#include <bits/stdc++.h>
using namespace std;
int minOperations(int n) {
    long long sum = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        sum += (2 * i + 1);
        arr[i] = (2 * i + 1);
    }
    int target = sum / n;
    int count = 0;
    for (int i = 0; i < n && arr[i] < target; i++) {
        count += (target - arr[i]);
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << minOperations(n) << endl;
}