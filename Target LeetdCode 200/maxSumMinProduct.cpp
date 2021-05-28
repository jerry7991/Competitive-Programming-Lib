#include <bits/stdc++.h>
using namespace std;

int maxSumMinProduct(vector<int>& nums) {
    int n = nums.size();

    // LeftMost[i] represent the farthest element which is greater than or equal to nums[i] in left side
    // rightMost[i] represent the farthest element which is greater than or equal to nums[i] in right side

    vector<int> leftMost(n), rightMost(n);

    vector<long long int> sum(n + 1);

    sum[0] = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + nums[i];

        // Find farthest
        while (st.size() && nums[st.top()] >= nums[i]) st.pop();
        if (st.size()) {
            leftMost[i] = st.top() + 1;
        } else {
            // This is the largest till now
            leftMost[i] = 0;
        }
        st.push(i);
    }

    while (st.size()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        // Find farthest from right side
        while (st.size() && nums[st.top()] >= nums[i]) st.pop();
        if (st.size()) {
            rightMost[i] = st.top() - 1;
        } else {
            // This is largest for right side till now
            rightMost[i] = n - 1;
        }
        st.push(i);
    }

    long long ans = 0;

    // let's suppose each nums[i] is the minimum
    for (int i = 0; i < nums.size(); i++) {
        ans = max(ans, (long long)nums[i] * (sum[rightMost[i] + 1] - sum[leftMost[i]]));
    }
    return ans % 1000000007;
}

int main() {
}