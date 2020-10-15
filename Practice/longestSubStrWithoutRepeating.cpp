#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
	int n=s.size();
	if(n==0 || n==1) return n;
	unordered_map<char,int> visited;
	int ans=0,st=0;
	for(int i=0; i<n ;i++){
		if(visited[s[i]]){
			st++;
		}
		ans=max(ans ,i-st+1);
		visited[s[i]]=i+1;
	}
	return ans;
}
int main(){
	string str;
	cin>>str;
	cout<<lengthOfLongestSubstring(str);
	return 0;
}