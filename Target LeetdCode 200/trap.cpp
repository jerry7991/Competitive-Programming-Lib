#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> leftMax(n + 1), rightMax(n + 1);
    leftMax[0] = 0, rightMax[n] = 0;
    for (int i = 1; i <= n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i - 1]);
        rightMax[n - i] = max(rightMax[n - i + 1], height[n - i]);
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        int x = min(leftMax[i], rightMax[i]) - height[i];
        if (x > 0) ans += x;
    }
    return ans;
}

// using stack
int trap(vector<int>& height) {
    int n = height.size(), i = 0, ans = 0;
    stack<int> index;
    while (i < n) {
        while (!index.empty() && height[i] > height[index.top()]) {
            int ht = index.top();
            index.pop();
            if (index.empty()) {
                break;
            }
            int dist = (i - index.top() - 1);
            ans += (min(height[i], height[index.top()]) - height[ht]) * (dist);
        }
        index.push(i);
        i++;
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