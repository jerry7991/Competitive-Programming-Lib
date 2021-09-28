#include <iostream>
using namespace std;
int main() {
	int n, fact{1};
	cin >> n;
	if (n < 0) cout << "Error";
	if (n == 0 || n == 1) cout << "1"; while (n != 0) {
		fact = fact * n; n--;
	}
	cout << fact;
	return 0;
}