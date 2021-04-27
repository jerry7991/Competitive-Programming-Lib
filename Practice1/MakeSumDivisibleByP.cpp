#include <bits/stdc++.h>
using namespace std;

int minSubarray(vector<int>& nums, int p) {
    int n = nums.size(), want = 0, cur = 0, need = 0;
    for (int i = 0; i < n; i++) need = (need + nums[i]) % p;

    if (need == 0) {
        return 0;
    }

    int res = n;

    unordered_map<int, int> last = {{0, -1}};

    for (int i = 0; i < n; i++) {
        cur = (cur + nums[i]) % p;
        last[cur] = i;

        want = (cur - need + p) % p;
        if (last.count(want))
            res = min(res, i - last[want]);
    }
    return res == n ? -1 : res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int p;
    cin >> p;
    cout << minSubarray(nums, p);
}