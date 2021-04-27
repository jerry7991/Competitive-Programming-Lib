#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size(), count = 0;

    vector<int> sum(n + 1);
    sum[0] = 0;
    for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i - 1];

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if ((sum[j] - sum[i - 1]) % k == 0) count++;
        }
    }
    return count;
}

int subarraysDivByKOP(vector<int>& nums, int k) {
    int n = nums.size(), count = 0;
    vector<int> sum(n + 1);
    vector<int> cnt(k);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + nums[i - 1];
    for (int x : sum) {
        cnt[(x % k + k) % k]++;
    }
    int ans = 0;
    for (int x : cnt) ans += (x * (x - 1)) / 2;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int k;
    cin >> k;
    cout << subarraysDivByK(v, k);
}