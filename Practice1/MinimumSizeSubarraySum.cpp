#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
	
	int n =nums.size();
	int ans = INT_MAX;
	int left=0,sum=0;
	for(int i=0;i<n;i++){
		sum+=nums[i];
		while(sum>=target){
			ans = min(ans, i-left+1);
			sum -=nums[left++];
		}

	}
	return ans !=INT_MAX ? ans : 0;
}

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int k; cin >> k;
	cout << minSubArrayLen(k , v) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) solve();
	return 0;
}