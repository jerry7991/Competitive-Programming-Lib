#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int subString(string s)
{
	long long totalSum=s[0]-'0';
	long long lastValue=s[0]-'0';
	for(int i=1 ; i<s.length();i++)
	{
		cout<<"hi";
		lastValue=lastValue*10+(s[i]-'0')*(i+1);
		lastValue = lastValue %MOD;
		totalSum =	( totalSum+lastValue )%MOD;
	}
	return totalSum;
}
int main()
{
	string n;
	getline(cin , n);
	cout<<subString(n);
	return 0;
}