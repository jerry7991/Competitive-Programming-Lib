#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define preDouble(x) cout<< fixed << setprecision(10)<<x
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;

void solve(vector<int>& nums, int k, vector<vector<int>> ans, int i ) {
	if (i == nums.size()) {
		if (k) return;
		for (auto x : ans) {
			for (auto y : x)cout << y << " ";
			cout << endl;
		}
		cout << "---------" << endl;
		return;
	}


	//	Either it can join a group
	for (int j = 0; j < ans.size(); j++) {
		ans[j].push_back(nums[i]);
		solve(nums, k, ans, i + 1);
		ans[j].pop_back();
	}

	// or create itself
	if (k) {
		ans.push_back({nums[i]});
		solve(nums, k - 1, ans, i + 1);
	}
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (int &i : v) cin >> i;
		vector<vector<int>> ans;
		solve(v, k, ans, 0);
	}
}