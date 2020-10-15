#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	int *arr=new int[n];
	for(int i=0 ;i<n ; i++) cin>>arr[i];
	int ans=INT_MAX,pwan=-1;
	for(int i=0 ; i<n ; i++){
		if(k%arr[i]==0){
			if(k/arr[i]<ans)
			{
				ans=k/arr[i];
				pwan=arr[i];
			}
		}
	}
	cout<<pwan<<'\n';
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--) solve();
    return 0;
}