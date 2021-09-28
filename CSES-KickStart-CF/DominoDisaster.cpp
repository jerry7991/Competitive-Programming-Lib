#include<bits/stdc++.h>
#define fastio	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long
#define us unordered_set
#define um unordered_map
#define unt unsigned int

using namespace std;


int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string str;
		cin >> str;

		string s = "";
		for (char ch : str) {
			if (ch == 'U') {
				s.push_back('D');
			} else if (ch == 'D') {
				s.push_back('U');
			} else {
				s.push_back(ch);

			}
		}
		cout << s << "\n";
	}
}