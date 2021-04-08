#include <bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> leftMul(n + 1);
    vector<int> rightMul(n + 1);

    rightMul[n] = 1;
    leftMul[0] = 1;

    for (int i = 1; i <= n; i++) {
        leftMul[i] = (leftMul[i - 1] * nums[i - 1]);
        rightMul[n - i] = (rightMul[n - i + 1] * nums[n - i]);
    }

    vector<int> mul(n);
    for (int i = 0; i < n; i++) {
        mul[i] = leftMul[i] * rightMul[i + 1];
    }
    return mul;
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> out = productExceptSelf(v);
    for (int i : out) cout << i << " ";
}