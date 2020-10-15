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
void solve(){
	int n;cin>>n;
	unordered_map<int,int> freq;
	for(int i=0 ; i<n ; i++){
		int x;cin>>x;
		freq[x]++;
	}
	map<int,int> freq1;
	for(auto x: freq){
		freq1[x.second]++;
	}
	int maxVal=0;
	for(auto x:freq1){
		maxVal=max(x.second , maxVal);
	}
	for(auto x:freq1){
		if(x.second==maxVal){
			cout<<x.first<<'\n';
			return;
		}
	}
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--) solve();
    return 0;
}