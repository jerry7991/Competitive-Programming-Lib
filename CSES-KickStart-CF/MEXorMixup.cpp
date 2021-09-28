#include<bits/stdc++.h>
using namespace std;

void print(int n) {
	cout << n << "\n";
}

int computeXOR(int n) {

	if (n % 4 == 0)
		return n;

	if (n % 4 == 1)
		return 1;

	if (n % 4 == 2)
		return n + 1;

	return 0;
}


void solve() {

	int a, b;
	cin >> a >> b;

	int mini = a;

	int temp = computeXOR(a - 1);


	if (temp == b) {
		print(mini);
		return;
	}

	int toget = temp ^ b;

	if (toget == a) {
		// 2 case
		print(mini + 2);
		return;
	}

	print(mini + 1);




}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}