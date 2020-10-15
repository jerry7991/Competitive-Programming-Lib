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
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int i=0 , odd=0 , even=0 , flag=0;
	while(i<n){
		if(arr[i])
		{
			i++;
		 continue;
		}
		int count=0;
		while(i<n && !arr[i]) count++ , i++;
		if(count%2){
			if(count==1){
				flag++;
			}else{
				odd++;
			}
		}else if(count){
			even++;
		}
	}
	if(odd%2){
		cout<<"Yes"<<'\n';
	}else if(even){
		cout<<"No"<<'\n';
	}else if(flag==1){
		cout<<"Yes"<<'\n';
	}else{
		cout<<"No"<<'\n';
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