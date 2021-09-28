#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define preDouble(x) cout<< fixed << setprecision(10)<<x
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;

int dp[300];
inline int common(vector<int>&first, vector<int> &sec) {
	int cnt = 0;
	for (int i = 0; i < first.size(); i++) {
		if (first[i] == sec[i])cnt++;
	}
	return cnt;
}

int solve(vector<vector<int>>& st, vector<vector<int>>& ment, int i, int mask) {
	if (i == st.size()) return 0;
	int &ans = dp[mask];
	if (ans != -1) return ans;
	ans = 0;
	for (int j = 0; j < ment.size(); j++) {
		if (mask & (1 << j))continue;
		ans = max(ans, common(st[i], ment[j]) + solve(st, ment, i + 1, mask | 1 << j));
	}
	return ans;
}
int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
	memset(dp, -1, sizeof dp);
	return solve(students, mentors, 0, 0);
}

int main() {
	fastio;
	int t = 1;
	// cin >> t;
	while (t--) {
		vector<vector<int>> students = {{1, 1, 0}, {1, 0, 1}, {0, 0, 1}};
		vector<vector<int>> mentors = [[1, 0, 0], [0, 0, 1], [1, 1, 0]];
		solve();
	}
}