#include <iostream>
using namespace std;
int gcd(int a ,int b){
	if(a==0)
		return b;
	return gcd(b%a , a);
}
int lcm(int a,int b){
	return (a*b)/gcd(a,b);
}
void solve(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0 ; i<n ; i++){
		cin>>*(arr+i);
	}
	int *c=new int[n];
	for(int i=0 ; i<n ; i++){
		c[i]=lcm(arr[i] , n);
	}
	int x=c[0];
	for(int i=1 ; i<n ; i++){
		x=gcd(x , c[i]);
		cout<<c[i]<<' ';
	}
	cout<<x<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}