#include <iostream>
#include <vector>
using namespace std;
int solve(int k , vector<vector<vector<int>>> &dp, vector<int>&prices , bool onGoing = false , int day = 0) {
	if (day == prices.size()) return 0;
	if (dp[day][k][onGoing] != -1) return dp[day][k][onGoing];
	int opt2 = solve(k, dp, prices, onGoing, day + 1);
	if (onGoing) {
		int opt1 = prices[day] + solve(k, dp, prices, !onGoing, day + 1);
		opt2 = max(opt1, opt2);
	} else {
		if (k > 0) {
			int opt1 = solve(k - 1, dp, prices, !onGoing, day + 1) - prices[day];
			opt2 = max(opt1, opt2);
		}
	}
	return dp[day][k][onGoing] = opt2;
}
int maxProfit(int k,vector<int> &prices){
	int n=prices.size();
	if(k>=n/2){
		//we can do as many transaction as we want
		int **dp=new int*[n];
		for(int i=0;i<n;i++) dp[i]=new int[2];
		dp[0][0]=0;
		dp[0][1]=-prices[0];
		for(int i=1;i<n;i++){
			dp[i][0]=max(dp[i-1][0] ,  dp[i-1][1]-prices[i]);
			dp[i][1]=max(dp[i-1][1] , dp[i-1][1]+prices[i]);
		}
		return max(dp[n-1][0] , dp[n-1][1]);
	}else{
		int ***dp=new int**[n];
		for(int i=0;i<n;i++){
			dp=new int**[k];
			for(int j=0;j<k;j++){
				dp[i][j]=new int[2];
				dp[i][j][0]=0;
				dp[i][j][1]=0;
			}
		}
		for(int i=0;i<n;i++) dp[i][0]=0;
		for(int i=1;i<n;i++){
			for(int j=0;j<k;j++){
				if(j==0)
					dp[i][j]=dp[i-1][j];
				else{
					dp[i][j]=max(dp[i][j])
				}
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	vector<int> prices(n);
	for (int i = 0; i < n; i++) {
		cin >> prices[i];
	}
	int k;
	cin >> k;
	cout << maxProfit(k, prices) << '\n';
}