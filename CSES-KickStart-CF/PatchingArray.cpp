#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long

using namespace std;

class Solution {
  public:

	int minPatches(vector<int>& nums, int n) {

		long mis = 1, added = 0, i = 0;

		while (mis <= n) {
			if (i < nums.size() && nums[i] <= mis) {
				mis += nums[i++];
			} else {
				mis += mis;
				added++;
			}
		}
		return added;
	}
};

int main() {
	fastio;
	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	for (int &i : v) cin >> i;

	cout << (new Solution())->minPatches(v, m);
}