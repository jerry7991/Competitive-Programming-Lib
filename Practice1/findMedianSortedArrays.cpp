#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<int> nums(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (nums1[i] <= nums2[j])
            nums[k++] = nums1[i++];
        else
            nums[k++] = nums2[j++];
    }
    while (i < n) {
        nums[k++] = nums1[i++];
    }
    while (j < m) {
        nums[k++] = nums2[j++];
    }
    if ((n + m) & 1) {
        return (double)nums[(n + m) / 2];
    } else {
        return ((double)(nums[(n + m) / 2] + nums[(n + m) / 2 - 1])) / 2;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < m; i++) cin >> nums2[i];
    cout << findMedianSortedArrays(nums1, nums2);
}