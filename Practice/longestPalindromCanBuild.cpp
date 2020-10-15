#include<bits/stdc++.h>
using namespace std;
int longestPalindrome(string s) {
	int n=s.size();
	if(n==0 || n==1) return n;
	map<char, int> freq;
	for(int i=0 ; i<n ; i++) freq[s[i]]++;
	bool flag=true;
	int maxLen=0;
	for(auto x: freq){
		if((x.second & 1)){
			if(flag){
				maxLen+=x.second;
				flag=false;
				continue;
			}else{
				maxLen+=x.second-1;
			}
		}else{
			maxLen+=x.second;
		}
	}
	return maxLen;
}
int main(){
	string str;
	cin>>str;
	cout<<longestPalindrome(str)<<'\n';
}