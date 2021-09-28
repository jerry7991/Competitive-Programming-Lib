#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
	int maxProduct(vector<int>& nums) {

		int max_mul = INT_MIN, posMul = 0, negMul = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				posMul = negMul = 0;
				max_mul = max(max_mul, 0);
			} else if (nums[i] < 0) {
				int lastPos = posMul;
				posMul = negMul * nums[i];
				negMul = (lastPos ? lastPos : 1) * nums[i];
			} else {
				posMul = (posMul ? posMul : 1) * nums[i];
				negMul = negMul * nums[i];
			}
			max_mul = max({max_mul , posMul ? posMul : INT_MIN, negMul ? negMul : INT_MIN});
		}
		return max_mul;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int &i : v)cin >> i;
		cout << (new Solution())->maxProduct(v) << endl;
	}
}