#include<bits/stdc++.h>
using namespace std;

pair<int, int> getTime(string str, string turn) {
	int hr, mt;
	int i = 0;
	pair<int, int> time;
	time.first = time.second = -1;
	while (i < str.size()) {
		int n = 0;
		while (i < str.size() && str[i] != ':') {
			n = n * 10 + (str[i] - '0');
			i++;
		}
		if (time.first == -1) {
			time.first = n;
		} else {
			time.second = n;
		}
		i++;
	}
	if (turn == "PM" && time.first != 12) {
		time.first += 12;
	} else if (turn == "AM" && time.first == 12) {
		time.first = 0;
	}
	return time;
}

void solve() {
	string av; string m;
	cin >> av >> m;

	pair<int, int> avaTime = getTime(av, m);
	int n;
	cin >> n;
	while (n--) {
		string st, stm, ed , edm;
		cin >> st >> stm >> ed >> edm;
		pair<int, int> stTime = getTime(st, stm);
		pair<int, int> edTime = getTime(ed, edm);

		if( (avaTime.first<stTime.first) 
			|| (avaTime.first>edTime.first) 
			|| (avaTime.first == stTime.first && avaTime.second<stTime.second) 
			|| (avaTime.first == edTime.first && avaTime.second>edTime.second) ){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) solve();
	return 0;
}