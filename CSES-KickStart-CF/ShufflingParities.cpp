#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;

int solve(vector<int>& v) {
	int n = v.size();
	int totalEven = n / 2;
	int totalOdd = n - totalEven;


	int oddCnt = 0, evenCnt = 0;

	for (int &i : v) {
		if (i % 2) {
			oddCnt++;
		} else {
			evenCnt++;
		}
	}

	int ans = ((oddCnt > totalEven) ? totalEven : oddCnt) + ((evenCnt > totalOdd) ? totalOdd : evenCnt);
	return ans;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int &i : v)cin >> i;
		cout << solve(v) << '\n';
	}

}