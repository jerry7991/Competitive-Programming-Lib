#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numOfWays(int n) {
        long mod = 1e9 + 7;
        vector<long> two(n + 1), three(n + 1);
        two[1] = three[1] = 6;
        for (int i = 2; i <= n; i++) {
            two[i] = (three[i - 1] * 2 + two[i - 1] * 2) % mod;
            three[i] = (2 * three[i - 1] + two[i - 1] * 2) % mod;
        }
        return (two[n] + three[n]) % mod;
    }
};

int main() {
    int n;
    cin >> n;
    cout << (new Solution())->numOfWays(n);
}