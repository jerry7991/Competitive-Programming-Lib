#include<bits/stdc++.h>
using namespace std;

int getPivotIndex(vector<int>&nums) {
	int st = 0 , en = nums.size() - 1, n = nums.size() - 1;
	while (st < en) {
		int mid = (st + en) / 2;
		if (nums[mid] >= nums[0] && nums[mid] > nums[n]) {
			st = mid + 1;
		} else if (nums[mid] < nums[0] && nums[mid] <= nums[n]) {
			en = mid - 1;
		}
	}
	return st;
}

int search(vector<int>& nums, int target) {
	int n = nums.size();
	int start = 0 , end = n - 1;
	if (nums[0] > nums[n - 1]) {
		int index = getPivotIndex(nums);
		if (nums[0] > target) {
			start = index;
			end = n - 1;
		} else {
			start = 0;
			end = index;
		}
	}

	while (start <= end) {
		int m = (start + end) / 2;
		if (nums[m] == target) {
			return m;
		} else if (nums[m] > target) {
			end = m - 1;
		} else {
			start = m + 1;
		}
	}
	return -1;
}


void solve() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int target; cin >> target;
	cout << search(nums, target) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) solve();
	return 0;
}