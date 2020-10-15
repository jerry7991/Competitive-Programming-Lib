#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &price ,int **dp ,unsigned int len=0  , bool onGoing=false){
	if(len>=price.size()) return 0;//we can't make money further
	//before calling the function we should check weather we have any solution for that or not
	if(dp[onGoing][len]!=-1) return dp[onGoing][len];
	int ans=0;
	if(onGoing){
		//we have two choice 
		//either we can sell the stock
		int sell=solve(price , dp , len+2 , false)+price[len];//if we sell,we get the money of current price
		//or not
		int notSell=solve(price ,dp ,len+1 , onGoing);
		ans=max(sell , notSell);
	}else{
		//we have two choice either we can buy or not
		int buy=solve(price  , dp , len+1 , true)-price[len];//if we perchase then have to pay
		int notBuy=solve(price , dp , len+1 ,false);
		ans=max(buy , notBuy);
	}
	//store the ans for current onGoing and len for future use to stop duplicates calls
	dp[onGoing][len]=ans;
	return ans;
}
int maxProfit(vector<int> & price){
	int **dp=new int*[2];
	//size 2 cause on each stock price we have two condition weather any onGoing transaction or nots
	dp[0]=new int[price.size()];
	dp[1]=new int[price.size()];
	for(unsigned int i=0 ; i <price.size() ; i++)
	{
		dp[0][i]=-1;
		dp[1][i]=-1;
	}
	int ans=solve(price,dp);
	//we have created the memory on heap so we should release that memory before returning the function
	delete []dp[0];
	delete []dp[1];
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