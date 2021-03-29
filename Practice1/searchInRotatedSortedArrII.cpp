#include<bits/stdc++.h>
using namespace std;


bool search(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1, n= nums.size()-1;
	
	while(left <= right){
		while(left < right && nums[left] == nums[left+1]) left++;
		while(left < right && nums[right] == nums[right-1]) right--;

		int mid = (left+right)/2;
		if(nums[mid] == target) return true;

		if(nums[mid]>=nums[left]){
			if(target>=nums[left] && target<nums[mid]){
				right = mid-1;
			}else{
				left = mid+1;
			}
		}else{
			if(target<nums[right] && target>nums[mid]){
				left = mid+1;
			}else{
				right = mid-1;
			}
		}
	}
	return false;
}


void solve() {
	int n; cin >> n;
	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int target; cin >> target;
	cout << search(nums, target) << '\n';
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