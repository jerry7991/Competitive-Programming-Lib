#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define preDouble(x) cout<< fixed << setprecision(10)<<x
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;

int solve(vector<vector<int>>& v) {
	int n  = v[0].size();
	int topSum = accumulate(v[0].begin(), v[0].end(), 0);
	int bottomSum = 0, res = INT_MAX;
	for (int i = 0; i < n; i++) {
		topSum -= v[0][i];
		res = min(res, max(topSum, bottomSum));
		bottomSum += v[1][i];
	}
	return res;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <vector<int>> v(2, vector<int>(n));
		for (int &i : v[0]) cin >> i;
		for (int &i : v[1]) cin >> i;
		cout << solve(v) << "\n";
	}
}