#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long n = arr.size(), sum = 0, subarr = INT_MIN, curr = 0, bps = INT_MIN, bss = INT_MIN;
        int mod = 1e9 + 7;
        vector<long long> ps(n), ss(n);
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            ps[i] = arr[i] + (i ? ps[i - 1] : 0);
            ss[n - i - 1] = arr[n - i - 1] + (i ? ss[n - i] : 0);
            curr += arr[i];
            subarr = max(subarr, curr);
            bps = max(ps[i], bps);
            bss = max(ss[n - i - 1], bss);
            if (curr < 0) curr = 0;
        }
        if (sum < 0) {
            long long ans = max((long long)0, max(subarr, (bps + bss) * (k > 1)));
            return ans % mod;
        } else {
            long long ans = max((long long)0, max(subarr, bps + bss + (k - 2) * sum));
            return ans % mod;
        }
    }
};