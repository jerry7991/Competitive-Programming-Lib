#include <iostream>
#define nMax 100000
using namespace std;
int max(int a,int b){
	if(a<b) return b;
	return a;
}
void solve(){
	int n;
	cin>>n;
	int nSkips=0;
	int *input=new int[n];
	for(int i=0 ; i<n ; i++){
		cin>>input[i];
	}
	for(int i=0 ; i<n-1 ; i++){
		if(input[i]!=input[i+1]) nSkips+=max(input[i]-input[i+1]-1 , input[i+1]-input[i]-1);
	}
	delete []input;
	cout<<nSkips<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}