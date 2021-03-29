#include<bits/stdc++.h>
using namespace std;

vector<int> shortestToChar(string s, char c) {
	vector<int> ans(s.size(), INT_MAX);
	int dist = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == c) {
			dist = 0;
		}
		if (dist != -1) {
			ans[i] = dist++;
		}
	}
	dist=-1;
	for(int i=s.size()-1; i>=0; i--){
		if(s[i]==c){
			dist=0;
		}
		if(dist!=-1){
			ans[i] = min(ans[i], dist);
			dist++;
		}
	}
	return ans;
}

void solve() {
	string str;
	cin >> str;
	char ch; cin >> ch;

	vector<int> v = shortestToChar(str, ch);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout<<endl;
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