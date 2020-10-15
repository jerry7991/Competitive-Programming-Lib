#include <bits/stdc++.h>
using namespace std;
int calculateMex(unordered_set<int> s)
{
	int mex=0;
	while(s.find(mex)!=s.end()) mex++;
	return mex;
}
int getGrandy(int n)
{
	if (n==0)
	{
		return 0;
	}
	unordered_set<int> s;
	s.insert(getGrandy(n/2));//for taking two steps
	s.insert(getGrandy(n/3));//for taking three steps
	s.insert(getGrandy(n/6));////for taking six steps
	return (calculateMex(s));
}
int main()
{
	int n;
	cin>>n;
	cout<<getGrandy(n);
}