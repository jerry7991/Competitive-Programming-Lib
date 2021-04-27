#include <bits/stdc++.h>
using namespace std;

// brute force
int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size(), ans = n;

    // Get all the sub-array
    for (int i = 0; i < n; i++) {
        for (int j = i; j <= n; j++) {
            int maxVal = INT_MIN, minVal = INT_MAX, prevVal = INT_MIN;

            int idx = i;
            // Get max and min value from current sub-array
            while (idx < j) {
                maxVal = max(maxVal, nums[idx]);
                minVal = min(minVal, nums[idx]);
                idx++;
            }

            if ((i > 0 && nums[i - 1] > minVal) || (j < n && nums[j] < maxVal)) {
                continue;
            }

            //  Validate left sub-array is well sorted[0,i-1]
            idx = 0;
            while (idx < i && prevVal <= nums[idx]) {
                prevVal = nums[idx++];
            }

            if (idx != i) continue;
            idx = j;

            //  Validate right sub-array[j,n] is well sorted with left part[0,i-1]
            while (idx < n && prevVal <= nums[idx]) {
                prevVal = nums[idx++];
            }

            if (idx != n) continue;
            ans = min(ans, j - i);
        }
    }
    return ans;
}

//  based on selection sort
int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    int left = n, right = 0;

    //  Find leftmost and rightMost unset data
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (nums[j] < nums[i]) {
                left = min(left, i);    //  Select only for the first time
                right = max(right, j);  // Select till the last time
            }
        }
    }
    return (right - left) < 0 ? 0 : (right - left + 1);
}

//   On sorting approach
int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<int> copy = nums;
    sort(copy.begin(), copy.end());
    int left = n, right = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != copy[i]) {
            left = min(left, i);    // Find first changed points
            right = max(right, i);  // Find last changed points
        }
    }
    return (right - left) < 0 ? 0 : (right - left + 1);
}

// Using stack
int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    int left = n;
    int right = 0;

    stack<int> st;

    //  Figure out the left most points from where we have to sort the sub-array
    for (int i = 0; i < n; i++) {
        while (st.size() && nums[i] < nums[st.top()]) {
            left = min(left, st.top());
            st.pop();
        }
        st.push(i);
    }

    while (st.size()) st.pop();

    //  Figure out the right most points till that we have to sort the sub-array
    for (int i = n - 1; i >= 0; i--) {
        while (st.size() && nums[i] > nums[st.top()]) {
            right = max(right, st.top());
            st.pop();
        }
    }

    return (right - left) < 0 ? 0 : (right - left + 1);
}

int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    int minVal = INT_MAX, maxVal = INT_MIN;
    bool flag = false;

    //  Get the minVal after one array started decreasing
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i - 1]) flag = true;
        if (flag) {
            minVal = min(minVal, nums[i]);
        }
    }

    //  Get the maxval after one array started decreasing on reverse
    flag = false;
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] > nums[i + 1]) flag = true;
        if (flag) {
            maxVal = max(maxVal, nums[i]);
        }
    }
    int r = n - 1, l = 0;

    while (l < n) {
        if (nums[l] > minVal) break;
        l++;
    }
    while (r >= 0) {
        if (nums[r] < maxVal) break;
        r--;
    }
    return (r - l) < 0 ? 0 : (r - l + 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << findUnsortedSubarray(v);
}