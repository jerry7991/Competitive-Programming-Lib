#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int one = 0, curr = 0;
        for (int i : nums) {
            if (!i) {
                curr = 0;
            }
            curr++;
            one = max(one, curr);
        }
        return one;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
