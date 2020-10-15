#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0 ; i<n ; i++) cin>>arr[i];
	int count=0;
	for(int i=0 ; i<n ; i++){
		for(int j=i+1 ; j<n ; j++){
			if(arr[i]==(arr[i]&arr[j])) count++;
		}
	}
	delete []arr;
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