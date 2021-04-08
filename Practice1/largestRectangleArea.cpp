#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int ans = 0;

    stack<int> st;  // storing indices

    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];

        if (!st.size() || h >= heights[st.top()]) {
            st.push(i);
        } else {
            int tp = st.top();
            st.pop();

            ans = max(ans, heights[tp] * (st.empty() ? i : (i - 1 - st.top())));
            i--;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    cout << largestRectangleArea(heights);
}