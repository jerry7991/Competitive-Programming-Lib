//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
	int solve(vector<int>& prices ,int *dp, int len=0 , bool onGoing=false){
		if(len>=prices.size()){
			return 0;
		}
		if(dp[len]!=-1)return dp[len];
		int ans=0;
		if(!onGoing){
			//we have two option
			//perchase stock
			int buy=solve(prices ,dp, len+1 , true)-prices[len];
			int notBuy=solve(prices ,dp, len+1 , false);
			ans=max(buy , notBuy);
		}else{
			//we have two option...
			//either we can sell the perchased stock or not
			int sell=solve(prices ,dp, len+2 , false)+prices[len];
			int notSell=solve(prices ,dp, len+1 , true);
			ans=max(sell , notSell);
		}
		return dp[len]=ans;
	}
	int maxProfit(vector<int>&prices){
		int *dp=new int[prices.size()];
		for(int i=0 ; i<prices.size();i++)	dp[i]=-1;
			return solve(prices , dp);
	}
};
int main(){
	int n;
	cin>>n;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	Solution *s=new Solution();
	cout<<s->maxProfit(v);
}