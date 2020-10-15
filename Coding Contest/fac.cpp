#include <bits/stdc++.h>
using namespace std;
double solve(int n , int k){
	if(k>n) return -1;
	for(int i=1 ; i<=n ; i++){
		if(n%i==0) k--;
		if(k==0) return i;
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	cout<<solve(n,k);
}