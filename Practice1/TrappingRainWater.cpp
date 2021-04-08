#include <bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
    int ans = 0, n = height.size();
    for (int i = 0; i < n; i++) {
        int leftMax = 0, rightMax = 0;
        for (int j = i - 1; j >= 0; j--) {
            leftMax = max(leftMax, height[j]);
        }
        for (int j = i + 1; j < n; j++) {
            rightMax = max(rightMax, height[j]);
        }

        ans += (min(leftMax, rightMax) - height[i]) > 0 ? (min(leftMax, rightMax) - height[i]) : 0;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) cin >> height[i];
    cout << trap(height);
}