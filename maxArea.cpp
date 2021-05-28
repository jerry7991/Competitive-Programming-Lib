#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1, ans = 0;

    while (left <= right) {
        ans = max(ans, (right - left) * min(height[left], height[right]));
        if (height[left] < height[right]) {
            left++;  //Greedy
        } else {
            right--;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) cin >> height[i];
    cout << maxArea(height);
}