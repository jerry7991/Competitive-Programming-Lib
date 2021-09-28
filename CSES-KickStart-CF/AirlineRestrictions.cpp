#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;


int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		vector<int> nums(3);
		int d, e;
		for (int &i : nums)cin >> i;
		cin >> d >> e;

		sort(nums.begin(), nums.end());
		int sum = accumulate(begin(nums), end(nums), 0);

		bool flag = true;

		for (int i = 0; i < 3 && flag; i++) {
			for (int j = i + 1; j < 3 && flag; j++) {
				int s = (nums[i] + nums[j]);
				flag &= !(s <= d && (sum - s) <= e);
			}
		}
		if (!flag) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
}