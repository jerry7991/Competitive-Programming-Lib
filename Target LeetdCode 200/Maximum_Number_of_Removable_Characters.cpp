#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
    }
};

int main() {
    string s, p;
    cin >> s >> p;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->maximumRemovals(s, p, nums);
}