#include <iostream>
using namespace std;

// Function to count number of times the pattern Y[0..n) 
// appears in given string X[0..m) as a subsequence
int count(string X, string Y, int m, int n)
{
	// Base case 1: if only one character is left
	if (m == 1 && n == 1)
		return (X[0] == Y[0]);

	// Base case 2: if input string X reaches its end,
	if (m == 0)
		return 0;

	// Base case 3: if pattern Y reaches its end, we have found subsequence
	if (n == 0)
		return 1;

	// Optimization: Solution is not possible if number of characters
	// in the string is less than number of characters in the pattern
	if (n > m)
		return 0;

	// if last character of both string and pattern matches,
	// 1. exclude last character in both string and pattern
	// 2. exclude only last character in the string

	// else if last character of string and pattern do not match, 
	// recur by excluding only last character in the string

	return ((X[m-1] == Y[n-1]) ? count(X, Y, m - 1, n - 1) : 0) +
			count(X, Y, m - 1, n);
}

int main()
{
	string X ;cin>>X; 
	string Y = "ROR";

	cout << count(X, Y, X.size(), Y.size());

	return 0;
}