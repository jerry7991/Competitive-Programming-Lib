#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
void seive(){
	bool isPrime[1000000];
	isPrime[2]=true;
	isPrime[1]=false;
	isPrime[0]=false;
	for(int i=3; i<1000000 ; i+=2) isPrime[i]=true;
	for(int i=2 ; i*i<1000000 ; i++){
		if(isPrime[i])
		{
			for(int j=i*i ; j<1000000 ; j+=i)	isPrime[j]=false;
		}
	}
	prime.push_back(1);
	for(int i=2 ; i<1000000;i++){
		if(isPrime[i]) prime.push_back(i);
	}
}
void solve(int n){
	int count=0,sum=0,i=0;
	while(sum<=n){
		sum+=prime[i++];
		count++;
	}
	cout<<count<<endl;
}
int main(){
	seive();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		solve(n);
	}
}