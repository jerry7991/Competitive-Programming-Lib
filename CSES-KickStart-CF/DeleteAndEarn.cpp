#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long

using namespace std;

class Solution {
  public:
	int deleteAndEarn(vector<int>& nums) {
		int n = 1e4 + 1;
		vector<int> freq(n, 0);

		for (int i : nums) freq[i]++;

		int avoid = 0, take = 0, prev = -1;

		for (int i = 0; i < n; i++) {
			if (!freq[i])continue;
			int m = max(avoid, take);

			if (i - 1 != prev) {
				take = i * freq[i] + m;
				avoid = m;
			} else {
				take  = i * freq[i] + avoid;
				avoid = m;
			}

			prev = i;

		}

		return max(avoid, take);

	}
};

int main() {
	fastio;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &i : v) cin >> i;

	cout << (new Solution())->deleteAndEarn(v);

}