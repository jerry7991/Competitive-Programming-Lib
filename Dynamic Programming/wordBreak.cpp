#include <bits/stdc++.h>
using namespace std;
bool solve(string str,unordered_map<string , int> validDict , unordered_map<string , int> found){
	if(str.size()==0) return true;
	if(found[str])
	bool ans=false;
	string currStr;
	for(int i=0; i<str.size() ; i++){
		currStr+=str[i];
		if(validDict[currStr]){
			ans=solve(str.substr(currStr.size() , str.size()) , validDict , found);
			if(ans){
				found[currStr]=1;
			}
		}
	}
	found[currStr]=-1;
	return ans;
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string , int> validDict;
    unordered_map<string , int> found;
    for(int i=0 ; i<wordDict.size() ; i++){
    	validDict[wordDict[i]]++;
    }
    bool ans=solve(s,validDict , found);
    return ans;
}
int main(){
	string str;
	vector<string> v;
	int n;
	cin>>str;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		v.push_back(s);
	}
	cout<<wordBreak(str , v);
}