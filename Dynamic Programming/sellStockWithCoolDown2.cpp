#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &price ,unsigned int len=0 , bool onGoing=false){
	if(len>=price.size())	return 0;
	int ans=0;
	if(onGoing){
		//then we have two choice either i can sell the current running stock or not
		int sell=solve(price , len+2 , false)+price[len];
		int notSell=solve(price , len+1 , onGoing);
		ans=max(sell , notSell);
	}else{
		//we have two choice either we can perchase a new stock or not
		int perchased=solve(price  , len+1 ,true)-price[len];
		int notPerchased=solve(price , len+1 , false);
		ans=max(perchased , notPerchased);
	}
	return ans;
}
int main(){
	int n;cin>>n;
	vector<int> price;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		price.push_back(x);
	}
	cout<<solve(price);
	return 0;
}