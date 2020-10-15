#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &prices,int ***dp, int nTransaction,unsigned int nDay=0 ,int onGoing=0 )
{
	if(nDay==prices.size()) return 0;
	if(dp[nDay][nTransaction][onGoing]!=-1) return dp[nDay][nTransaction][onGoing];
	int ans=0;
	if(onGoing){
		//either we can sell or not
		int sell=solve(prices ,dp,nTransaction-1, nDay+1 , 0 )+prices[nDay];//one trancsactino complited
		int notSell=solve(prices,dp,nTransaction,nDay+1 ,onGoing);
		ans=max(sell , notSell);
	}else{
		//we can buy only if we have any left transaction
		if(nTransaction>0){
			int buy=solve(prices ,dp,nTransaction, nDay+1 ,1)-prices[nDay];
			int notBuy=solve(prices ,dp,nTransaction, nDay+1 , onGoing );
			ans=max(buy , notBuy);
		}
	}
	return dp[nDay][nTransaction][onGoing]=ans;
}
int maxProfit(std::vector<int>& prices,int nTransaction=2){
	int n=prices.size();
	if(n<2) return 0;
	else if(nTransaction>=(n/2)){
	//then problem will just like constraint free transaction as sellStock4
	int **dp=new int*[2];
	dp[0]=new int[n];
	dp[1]=new int[n];
	//base case
	dp[0][0]=0;
	dp[1][0]=-prices[0];
	for(int i=1;i<n ; i++){
		dp[0][i]=max(dp[1][i-1]+prices[i] , dp[0][i-1]);
		dp[1][i]=max(dp[0][i-1]-prices[i] , dp[1][i-1]);
	}
	int ans=max(dp[0][n-1] , dp[1][n-1]);
	delete []dp[0];delete []dp[1];
	return ans;
	}
	int ***dp=new int**[prices.size()+1];
	for(unsigned int i=0 ; i<=prices.size() ; i++){
		dp[i]=new int*[nTransaction+1];
		for(int j=0 ; j<=nTransaction;j++){
			dp[i][j]=new int[2];
			dp[i][j][0]=-1;
			dp[i][j][1]=-1;
		}
	}
	int ans=solve(prices , dp,nTransaction);
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
}