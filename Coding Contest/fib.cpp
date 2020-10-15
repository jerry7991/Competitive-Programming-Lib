#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;
bool isPrime(int n){
	for(int i=2;i*i<=n ; i++){
		if(!(n%i))	return false;
	}
	return true;
}
void printFab(ull first , ull second , int n){
	ull third=0;
	if(n==1){
		cout<<first;
		return;
	}
	if(n==2){
		cout<<second;
		return;
	}
	n-=2;
	while(n--){
		third=first+second;
		first=second;
		second=third;
		//cout<<third<<endl;
	}
	cout<<third;
}
void solve(int n1,int n2)
{
	vector<int> out;
	for(int i=n1 ; i<=n2 ; i++){
		if(isPrime(i)){
			out.push_back(i);
		}
	}
	int x=out.size();
	for(int i=0 ; i<x ; i++){
		int y=out[i];
		for(int j=0;j<x ; j++){
			if(i==j) continue;
			int x=out[j];
			int digit=0;
			while(x){
				x/=10;
				digit++;
			}
			out.push_back((y*pow(10,digit))+out[j]);
		}
	}
	set<int> prime;
	for(unsigned int i=x ; i<out.size();i++){
		if(isPrime(out[i]) && (prime.count(out[i])==0))	prime.insert(out[i]);
	}
	int Min=INT_MAX , Max=INT_MIN;
	for(auto i=prime.begin();i!=prime.end();i++)
	{
		Min=min(*i , Min);
		Max=max(*i , Max);
	}
	//cout<<Min<<" "<<Max<<" "<<prime.size()<<endl;
	printFab(Min , Max , prime.size());
}
int main(){
	int n1,n2;
	cin>>n1>>n2;
	solve(n1,n2);
}