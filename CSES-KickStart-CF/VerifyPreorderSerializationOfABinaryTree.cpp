#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
	bool isValidSerialization(string preorder) {
		stringstream ss(preorder);
		vector<string> v;

		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			v.push_back(substr);
		}

		int diff = 1;
		for (string s : v) {
			if (--diff < 0) return false;
			if (s != "#") diff += 2;
		}
		return diff == 0;
	}
};

int main() {
	string preorder;
	cin >> preorder;
	cout << (new Solution())->isValidSerialization(preorder);
}