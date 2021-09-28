#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long

using namespace std;



int solve(string &r, int x, int n , bool tight = true) {
	if (x < 0) return 0;
	if (n == 1) {
		return x >= 0 && x < 10;
	}

	int ub = tight ? (r[r.size() - n] - '0') : 9;

	int ans = 0;
	for (int i = 0; i <= ub; i++) {
		ans += solve(r, x - i, n - 1, (tight & (i == ub)));
	}
	return ans;
}

int main() {
	fastio;
	string r;
	cin >> r;
	int x;
	cin >> x;
	cout << solve(r, x, r.size());
}