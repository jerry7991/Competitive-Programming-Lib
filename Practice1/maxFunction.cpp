#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	long m = INT_MIN;

	sort(v.begin(), v.end());

	m = 2*(long)(v[v.size()-1]-v[0]);

	cout<<m<<'\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) solve();
	return 0;
}