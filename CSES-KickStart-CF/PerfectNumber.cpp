#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;

ll solve(ll k) {
	ll i = 19;
	while (true) {
		ll sum = 0, x = i;
		while (x && sum <= 10) {
			sum += x % 10;
			x /= 10;
		}
		if (sum == 10) k--;
		if (k == 0) return i;
		i++;
	}
}

int main() {
	fastio;
	int t = 1;
	while (t--) {
		ll k;
		cin >> k;
		cout << solve(k);
	}
}