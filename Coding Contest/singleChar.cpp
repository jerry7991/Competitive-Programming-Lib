#include<bits/stdc++.h>
using namespace std;
struct Char
{
	int index;int freq;
};
bool compare(Char c1, Char c2){
	if(c1.freq==c2.freq){
		return c1.index<c2.index;
	}
	return c1.freq>c2.freq;
}
void solve(){
	string str;
	cin>>str;
	int freq[27]{0};
	for(int i=0 ; i<str.size() ; i++){
		freq[str[i]-'a']++;
	}
	Char ans[27];
	for(int i=0 ; i<27 ; i++){
		ans[i].index=i;
		ans[i].freq=freq[i];
	}
	sort(ans,ans+27 , compare);
	for(int i=0 ; i<ans[0].freq ; i++) cout<<(char)(ans[0].index+'a');
	cout<<""<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}