#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> countSmaller(vector<int>& nums) {
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<int> ans = (new Solution())->countSmaller(nums);
    for (auto x : ans) cout << x << " ";
}
