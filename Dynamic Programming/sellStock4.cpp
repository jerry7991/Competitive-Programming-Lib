#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> prices ,unsigned int day=0  , bool onGoing=false)
{
	if(day==prices.size())	return  0;
	int ans=0;
	if (onGoing)
	{
		int sell=prices[day]+maxProfit(prices , day+1 , false);
		int notSell=maxProfit(prices , day+1 , onGoing);
		ans=max(sell , notSell);
	}else{
		int buy=maxProfit(prices  , day+1 , true)-prices[day];
		int notBuy=maxProfit(prices , day+1, onGoing);
		ans=max(buy ,notBuy);
	}
	return ans;
}
int solve(vector<int> prices){
	int n=prices.size();
	if(n<2) return 0;
	int **dp=new int*[2];
	dp[0]=new int[n];
	dp[1]=new int[n];
	//base case
	dp[0][0]=0;
	dp[1][0]=-prices[0];
	//dp[0][1]=0;
	for(int i=1;i<n ; i++){
		dp[0][i]=max(dp[1][i-1]+prices[i] , dp[0][i-1]);
		dp[1][i]=max(dp[0][i-1]-prices[i] , dp[1][i-1]);
	}
	int ans=max(dp[0][n-1] , dp[1][n-1]);
	// for(int i=0 ;i<n ; i++) printf("%d  ", dp[0][i]);
	// printf("\n");
	// for(int i=0 ;i<n ; i++) printf("%d  ", dp[1][i]);
	delete []dp[0];
	delete []dp[1];
	return ans;
}
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
	cout<<maxProfit(v)<<endl;
	cout<<solve(v);
}