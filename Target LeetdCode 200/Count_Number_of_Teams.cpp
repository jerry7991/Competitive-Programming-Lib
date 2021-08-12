#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numTeams(vector<int>& rating) {
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (new Solution())->numTeams(nums);
}