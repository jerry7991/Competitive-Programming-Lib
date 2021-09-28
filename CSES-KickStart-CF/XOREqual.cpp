#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;

void solve(vector<int>&v, int x) {
	um<int, int> freq;
	um<int, int> seen;
	int n = v.size();

	for (int &i : v) {
		freq[i]++;
		seen[i] = 1;
	}

	if (n == 1) {
		cout << 1 << " " << 0 << '\n';
		return ;
	}

	int res = 0, count = 0;

	for (auto itr : freq) {
		res = max(res, itr.second);
		if (res == n) break;
	}

	if (x == 0) {
		cout << res << " " << count << '\n';
		return;
	}

	for (auto itr : freq) {
		int i = itr.first;

		int xor_i = i ^ x;

		if (seen[xor_i] == 1) {
			if (freq[xor_i] + freq[i] > res) {
				res = freq[xor_i] + freq[i];
				count = min(freq[xor_i], freq[i]);
			} else if (freq[i] + freq[xor_i] == res) {
				if (min(freq[i], freq[xor_i]) < count) {
					count = min(freq[i], freq[xor_i]);
				}
			}
		}
	}
	cout << res << " " << count << "\n";

}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> v(n);
		for (int &i : v) cin >> i;
		solve(v, x);
	}
}