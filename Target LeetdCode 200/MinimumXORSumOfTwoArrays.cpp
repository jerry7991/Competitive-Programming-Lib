#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i = 0) {
        if (nums1.size() == i) {
            return 0;
        }
        int ans = 1e8;
        for (int j = 0; j < nums2.size(); j++) {
            if (nums2[j] != -1) {
                int x = nums1[i] ^ nums2[j];
                int y = nums2[j];
                nums2[j] = -1;
                ans = min(ans, solve(nums1, nums2, i + 1) + x);
                nums2[j] = y;
            }
        }
        return ans;
    }

    int ans = INT_MAX;
    void allPerm(vector<int>& nums1, vector<int>& nums2, int i = 0) {
        if (i == nums2.size()) {
            int x = 0;
            for (int j = 0; j < nums1.size(); j++) x += (nums1[j] + nums2[j]);
            ans = min(ans, x);
        }
        for (int j = i; j < nums2.size(); j++) {
            swap(nums2[i], nums2[j]);
            allPerm(nums1, nums2, i + 1);
            swap(nums2[i], nums2[j]);
        }
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        // return solve(nums1,nums2);
        allPerm(nums1, nums2);
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums1(n), nums2(n);
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < n; i++) cin >> nums2[i];

    cout << (new Solution())->minimumXORSum(nums1, nums2);
}

