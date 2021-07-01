#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& n1, vector<int>& n2) {
        if (n1.size() * 6 < n2.size() || n2.size() * 6 < n1.size()) return -1;
        int sum1 = accumulate(begin(n1), end(n1), 0), sum2 = accumulate(begin(n2), end(n2), 0);
        if (sum1 > sum2) swap(n1, n2);
        int diff = abs(sum1 - sum2), count = 0;
        vector<int> cnt(6, 0);
        for (int n : n1) cnt[6 - n]++;  // We can increase only
        for (int n : n2) cnt[n - 1]++;  // We can decrease only

        for (int i = 5; i > 0 && diff > 0; i--) {
            int take = min(cnt[i], diff / i + (diff % i != 0));  // One step up
            diff -= (take * i);
            count += take;
        }
        return count;
    }
};

int main() {
    int n, v;
    cin >> n >> v;
    vector<int> n1(n), v1(v);
    for (int i = 0; i < n; i++) cin >> n1[i];
    for (int i = 0; i < v; i++) cin >> v1[i];
    cout << (new Solution())->minOperations(n1, v1);
}