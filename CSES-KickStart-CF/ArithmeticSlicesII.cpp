#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define preDouble(x) cout<< fixed << setprecision(10)<<x
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;

int solve(vector<int>& v, int i = 0, int cnt = 0, int diff = -1, int last = -1) {
	if (i == v.size()) {
		return cnt > 2 && diff != -1;
	}
	int res = 0;
	if (last == -1 || abs(last - v[i]) == diff) {
		res += solve();
	}
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int &i : v) cin >> i;
		cout << solve(v) << endl;
	}
}