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
	int n,k;
	cin>>n>>k;
	int *arr=new int[n];
	fon(i,n) cin>>arr[i];
	int count=-1 ,index=0;
	while(index<n && arr[index]<=k){
		if(count<0) count=0;
		count++;
		int sum=arr[index];
		index+=1;
		while(sum+arr[index]<=k){
			sum+=arr[index];
		 index++;
		}
	}
	if(index<n)
		cout<<"-1"<<'\n';
	else
	cout<<count<<'\n';
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--) solve();
    return 0;
}