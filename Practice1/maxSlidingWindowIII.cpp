#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> out;

    // Used to store the index of window
    deque<int> windowIndex;

    //  Get the index
    for (int i = 0; i < k; i++) {
        if (!windowIndex.size() || nums[windowIndex.back()] >= nums[i])
            windowIndex.push_back(i);
        else {
            while (windowIndex.size() && nums[windowIndex.back()] < nums[i]) {
                windowIndex.pop_back();
            }
            windowIndex.push_back(i);
        }
    }

    for (int i = k; i <= nums.size(); i++) {
        out.push_back(nums[windowIndex.front()]);

        // Remove element out of window size of k
        while (windowIndex.size() && windowIndex.front() <= i - k) {
            windowIndex.pop_front();
        }

        // Remove elemenet from window which is less than current element
        while (windowIndex.size() && nums[i] > nums[windowIndex.back()]) {
            windowIndex.pop_back();
        }

        windowIndex.push_back(i);
    }
    out.push_back(nums[windowIndex.front()]);
    return out;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int k;
    cin >> k;
    vector<int> out = maxSlidingWindow(v, k);
    for (int i : out) cout << i << " ";
}