#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> & price){
	if(price.size()<2) return 0;//for avoid heap buffer error for null price list
	int **dp=new int*[2];
	dp[0]=new int[price.size()];// no ongoing transaction
	dp[1]=new int[price.size()];//Yes OnGoing transaction
	dp[0][0]=0;//cause no sell ,no buy , no profit
	dp[1][0]=-price[0];//cause have bought one stock and did not yet sell.. so profit will be -price[0]
	dp[0][1]=max(0,dp[1][0]+price[1]);//we sell first stock just next day
	dp[1][1]=max(dp[1][0],-price[1]);//max of(we make a new transaction with first stock price,or same as before)

	for(unsigned int i =2 ; i<price.size() ; i++){
		dp[0][i]=max(dp[0][i-1] , dp[1][i-1]+price[i]);
		//i.e. max of(skip the current stock , or make a transaction)
		dp[1][i]=max(dp[0][i-2]-price[i] ,dp[1][i-1]);
		//i.e. max of(make a transaction from i-2 as a cool down with 0(no ongoing transaction) , or let this transaction as onGoing)
	}
	int ans=max(dp[0][price.size()-1] , dp[1][price.size()-1]);
	//since we have created memory on heap so before returning the function we should clear it..
	delete []dp;
	return ans;
}
int main(){
	int n;cin>>n;
	vector<int> price;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		price.push_back(x);
	}
	cout<<maxProfit(price);
	return 0;
}