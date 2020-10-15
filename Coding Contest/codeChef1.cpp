#include <iostream>
using namespace std;
void solve(){
	string str;
	cin>>str;
	int freq[27]{0};
	for(int i=0 ; i<str.size() ; i++) freq[str[i]-'a']++;
	for(int i=0 ; i<27 ; i++){
		if(freq[i]&1){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}