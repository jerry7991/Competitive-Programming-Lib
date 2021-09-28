#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define preDouble(x) cout<< fixed << setprecision(10)<<x
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;

bool solve(vector<int>& nums, int i, int k, vector<int> group) {
	if (i == nums.size()) {
		if (k) return false;
		for (int j = 0; j < group.size() - 1; j++) {
			if (group[j] != group[j + 1]) return false;
		}
		return true;
	}
	bool ans = false;
	for (int j = 0; j < group.size(); j++) {
		group[j] += nums[i];
		ans |= solve(nums, i + 1, k, group);
		group[j] -= nums[i];
	}


	if (k) {
		group.push_back(nums[i]);
		ans |= solve(nums, i + 1, k - 1, group);
	}
	return ans;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
	vector<int> group;
	return solve(nums, 0, k, group);
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> nums(n);
		for (int &i : nums) cin >> i;
		int k;
		cin >> k;
		cout << canPartitionKSubsets(nums, k) << endl;
	}
}