#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k,i;
	cin>>n>>k;
	long long int sum=0;
	int *arr=new int[n];
	for( i=0 ; i<n ; i++) cin>>arr[i];
	i=0;
	while(i<n){
			sum+=arr[i];
		if(sum<k){
			cout<<i+1<<endl;
			return;
		}
		sum-=k;
		i++;
	}
	cout<<i+(sum/k)+1<<'\n';
	delete []arr;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--) solve();
    return 0;
}
