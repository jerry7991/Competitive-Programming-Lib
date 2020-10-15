#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long x,b;
		cin>>x>>b;
		if(x%b==0){
			cout<<0<<endl;
			continue;
		}else{
			long ans=x%b;
			cout<<b-ans<<endl;
		}
	}
}