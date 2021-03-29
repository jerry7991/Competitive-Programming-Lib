#include<bits/stdc++.h>
using namespace std;
int findLHS(vector<int>& nums) {

	int mn = INT_MAX , mx = INT_MIN, dif = INT_MAX;

	for (int i : nums)	{
		int count = 0;
		bool flag = false;
		for (int j : nums) {
			if (nums[i] == nums[j]) {
				count++;
			} else if (nums[j] + 1 == nums[i]) {
				count++;
				flag = true;
			}
		}
		if (flag) {
			res = max(count , res)	;
		}
	}
	return res;

}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	cout << findLHS(nums) << '\n';
	return 0;
}
