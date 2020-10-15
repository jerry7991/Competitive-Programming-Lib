#include <bits/stdc++.h>
using namespace std;
//Recusrive solution
int coinChange1(vector<int>&coins , int amount,int start=0){
	if(start==coins.size()) 
	{
		if (amount==0)
		{
			return 0;
		}
		return 1000000;
	}
	int ignore=coinChange(coins , amount ,start+1);
	if(coins[start]<=amount){
		int taken=1+coinChange(coins , amount-coins[start] , start);
		ignore=min(ignore , taken);
	}
	return ignore;
}
int coinChange(vector<int> &coins , int amount){
	int n=coins.size();
	if(n==0 || amount==0)	return 0;
	if(n<2){
		if(amount%coins[0])	return -1;
		return amount/coins[0];
	}
	int **dp=new int*[2];
	for(int i=0  ; i<=1 ; i++) dp[i]=new int[amount+1];
	//base case
	for(int i=0 ; i<=1 ; i++){
		dp[i][0]=1000000;//can't make any coint with length 0
	}
	for(int i=0 ; i<=amount; i++){
		dp[0][i]=1000000;//0 possible for making 0 coin
	}
	dp[0][0]=0;
	int flag=1;
	for(int i=1;i<=n;i++){
		for(int j=0 ; j<=amount ; j++){
			dp[flag][j]=dp[flag^1][j];
			if(j>=coins[i-1]){
				dp[flag][j]=min(dp[flag][j] , 1+dp[flag][j-coins[i-1]]);
			}
		}
		flag^=1;
	}
	int ans=dp[flag^1][amount];
	delete []dp[0];
	delete []dp[1];
	if(ans==1000000)
		return -1;
return ans;
}
int main(){
	int n;
	cin>>n;
	vector<int>coins;
	for(int i=0 ; i<n ; i++){
		int x;
		cin>>x;
		coins.push_back(x);
	}
	int amount;cin>>amount;
	cout<<coinChange(coins , amount);
}