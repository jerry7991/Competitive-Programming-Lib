#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define preDouble(x) cout<< fixed << setprecision(10)<<x
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;

double probability[20][20];
double dp[(1 << 19)];


// fish is going to be die
double pMove(int bitMask , int fish, int &n) {
	int cnt = __builtin_popcount(bitMask);

	ll den = (cnt * (cnt - 1)) / 2; // we can select kc2 way to make pair fish with other

	double prob = 0;
	for (int i = 0; i < n; i++) {
		// if i-th fish is alive than only we can make fight
		if ((1 << i) & bitMask) {
			// let's i fight with fish and fish will be died
			prob += probability[i + 1][fish + 1];
		}
	}
	return prob / (1.0 * den);

}

double solve(int bitMask , int& n) {
	int alive = __builtin_popcount(bitMask);
	if (alive == n) {
		return 1;
	}
	if (dp[bitMask] > -0.9) {
		return dp[bitMask];
	}

	double res = 0;

	for (int fish = 0; fish < n; fish++) {
		// first fish should be dead for today
		if (!(bitMask & (1 << fish))) {

			int prevBitMask = bitMask ^ (1 << fish);

			double prevDay = solve(prevBitMask, n);

			res += prevDay * pMove(prevBitMask , fish, n);

		}
	}
	return dp[bitMask] = res;
}

int main() {
	fastio;
	int t = 1;
	while (t--) {
		int n;
		cin >> n;

		memset(dp, -1, sizeof dp);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) cin >> probability[i][j];
		}
		for (int i = 0; i < n; i++)
			preDouble(solve((1 << i), n)) << " ";
	}
}