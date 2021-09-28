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
		int n, a, b;
		cin >> n >> a >> b;
		string str;
		cin >> str;


		int one = 0, zero = 0;
		for (char &ch : str) {
			if (ch == '0') {
				zero++;
			} else {
				one++;
			}
		}

		cout << (a * zero + b * one) << '\n';
	}
}