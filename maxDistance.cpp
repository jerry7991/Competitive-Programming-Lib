#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size(), i = 0, j = 0, total = 0;

    while (i < n && j < m) {
        if (nums1[i] <= nums2[j]) {
            total = max(total, j - i);
            j++;
        } else if (i < j) {
            i++;
        } else {
            j++;
        }
    }
    return total;
}