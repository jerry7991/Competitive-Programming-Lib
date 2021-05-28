#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> first, second;
        int n = nums1.size(), count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                first[nums1[i] + nums2[j]]++;
                second[nums3[i] + nums4[j]]++;
            }
        }

        for (auto it = first.begin(); it != first.end(); it++) {
            if (second.count(0 - (it->first))) {
                count += (it->second * second[0 - (it->first)]);
            }
        }

        return count;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums1(n);
    vector<int> nums2(n);
    vector<int> nums3(n);
    vector<int> nums4(n);

    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < n; i++) cin >> nums2[i];
    for (int i = 0; i < n; i++) cin >> nums3[i];
    for (int i = 0; i < n; i++) cin >> nums4[i];

    cout << (new Solution())->fourSumCount(nums1, nums2, nums3, nums4);
    return 0;
}
