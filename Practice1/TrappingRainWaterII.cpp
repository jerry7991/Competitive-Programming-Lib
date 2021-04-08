#include <bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return n;
    vector<int> leftMax(n);
    vector<int> rightMax(n);
    leftMax[0] = height[0];
    rightMax[n - 1] = height[n - 1];
    for (int i = 1; i < n - 1; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
        rightMax[n - i - 1] = max(rightMax[n - i], height[n - i - 1]);
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        ans += (min(leftMax[i - 1], rightMax[i + 1]) - height[i]) > 0 ? (min(leftMax[i - 1], rightMax[i + 1]) - height[i]) : 0;
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