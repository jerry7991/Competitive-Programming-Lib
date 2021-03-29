#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i = 0, n = 1;
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] <= 0 || (i > 0 && nums[i] == nums[i - 1])) {
            continue;
        } else if (nums[i] != n) {
            return n;
        } else {
            n++;
        }
    }
    return n;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << firstMissingPositive(arr) << endl;
}