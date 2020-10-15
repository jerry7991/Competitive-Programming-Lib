#include<bits/stdc++.h>
using namespace std;
int solve(string s){
	 unordered_set<string> f;
        int n=s.size();
        for(int i=0 ; i<n;i++){
            string str;
            for(int j=i ; j<n ; j++){
                str=s.substr(i,j);
                f.insert(str);
            }
        }
        int ans=0;
        for(auto x:f) {
            // ans=max(ans  , x.size());
            cout<<x<<endl;
        }
        return ans;
}
int main(){
	while(true){
	string str;cin>>str;
	cout<<solve(str);
}
 return 0;
}
		