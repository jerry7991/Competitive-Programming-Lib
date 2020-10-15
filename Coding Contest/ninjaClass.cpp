#include <iostream>
#define ull unsigned long long int
using namespace std;
void solve(){
	int n;
	cin>>n;
	ull *arr=new ull[n+1];
	ull *ans=new ull[n+1];
	for (int i = 1; i <= n; ++i)
	{
		cin>>arr[i];
		ans[i]=arr[1];
	}
	for(int i=2; i<=n ; i++){
		for(int j=i ; j<=n ; j+=i) ans[j]+=arr[i];
	}
for(int i=1 ; i<=n ; i++) cout<<ans[i]<<' ';	
    cout<<endl;
delete []arr;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) solve();
}