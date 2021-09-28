#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define preDouble(x) cout<< fixed << setprecision(10)<<x
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;


int solve(vector<int> &nums, int i) {
	if (i == nums.size()) {
		return 1;
	}

	int ans = 0;
	for (int j = i; j < nums.size(); j++) {
		if (nums[j] % (i + 1) == 0 || (i + 1) % nums[j] == 0) {
			swap(nums[i], nums[j]);
			ans += solve(nums, i + 1);
			swap(nums[i], nums[j]);
		}
	}
	return ans;
}

int countArrangement(int n) {
	vector<int> nums(n);
	for (int i = 0; i < n; i++) nums[i] = i + 1;
	return solve(nums, 0);
}


int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << countArrangement(n) << endl;
	}
}