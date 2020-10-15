#include <bits/stdc++.h>
using namespace std;
bool solve(string str, unordered_map<string , int>&validWord){
	bool *dp=new bool[str.size()+1];
	for(unsigned int i=0 ; i<=str.size();i++)dp[i]=false;
	dp[0]=true;
	for(unsigned int i=1;i<=str.size();i++){
		//check for each sub string which is valid
		for( int j=i-1 ;j>=0 ; j--){
			if(dp[j]){
				string curr=str.substr(j , i-j);
				if(validWord[curr]){
					dp[i]=true;
					break;
				}
			}
		}
	}
	bool ans=dp[str.size()];
	delete []dp;
	return ans;
}
bool wordBreak(string str , vector<string> &dictornary){
	if(dictornary.size()==0) return false;
	unordered_map<string ,int> validWord;
	for(unsigned int i=0 ; i<dictornary.size();i++){
		validWord[dictornary[i]]++;
	}
	return solve(str , validWord);
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