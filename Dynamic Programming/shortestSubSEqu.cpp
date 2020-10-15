#include<bits/stdc++.h>
using namespace std;
int solve(string str1 , string  str2 , int s1=0 ,int s2=0)
{
	if(s2==str2.length())	return 1;
	if(s1==str1.length()) return 1001;
	//exclude first character
	int opt1=solve(str1 , str2 , s1+1 , s2);
	//we include 
}
int main()
{
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;
	return 0;
}