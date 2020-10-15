#include<bits/stdc++.h>
using namespace std;
void solve(){
	string str;
	cin>>str;
	int n=str.size()-1;
	for(int i=0 ; i<str.size();  i++){
		if(str[i]==str[i+1] && str[i+1]=='1') str[i]='0';
	}
	cout<<str<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}
#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define infinte 2147483647
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define ui	unsigned int
#define ll long long
#define ull unsigned long long 
#define uos unordered_set
#define ump unordered_map
#define mp make_pair
using namespace std;
inline int max(int a,int b){ return (a>b)?a:b;}
inline int min(int a,int b){ return (a>b)?b:a;}
int main(){

    return 0;
}