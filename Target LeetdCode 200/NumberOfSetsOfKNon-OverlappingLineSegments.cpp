#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001] = {};
class Solution {
   public:
    int numberOfSets(int n, int k) {
        if (n - k < 1 || k == 0)
            return k == 0;
        if (dp[n][k] == 0) {
            dp[n][k] = 1 + numberOfSets(n - 1, k);
            for (int i = n; i - k > 0; --i)
                dp[n][k] = ((long)dp[n][k] + numberOfSets(i - 1, k - 1)) % 1000000007;
        }
        return dp[n][k] - 1;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    cout << (new Solution())->numberOfSets(n, k);
}