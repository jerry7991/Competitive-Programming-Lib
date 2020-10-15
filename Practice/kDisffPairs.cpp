#include <bits/stdc++.h>
using namespace std;
int findPairs(vector<int>& nums, int k) {
	unordered_map<int, int> freq;
	for (auto x : nums) freq[x]++;
	int ans = 0;
	if (k == 0) {
		for(auto x:freq) ans+=x.second>2;
	}else{
		for(auto x:freq){
			if(freq.find(x.first-k)!=freq.end()){
				ans++;
			}
		}
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int k;
	cin >> k;
	cout << findPairs(v, k) << endl;
	return 0;
}