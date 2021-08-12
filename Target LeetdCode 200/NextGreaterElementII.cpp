#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, INT_MIN);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && st.top() <= nums[i]) st.pop();
            ans[i] = st.size() ? st.top() : -1;
            st.push(nums[i]);
        }

        return ans;
    }
};