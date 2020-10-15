#include <bits/stdc++.h>
using namespace std;
int main()
{
	string source;
	string destination;
	cin>>source>>destination;
	map<string , pair<string,int>> path;
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		string s1,d1;int cost;
		cin>>s1>>d1>>cost;
		path[s1]=make_pair(d1,cost);
	}
	return 0;
}