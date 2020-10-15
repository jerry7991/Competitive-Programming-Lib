#include <iostream>
#include <vector>
using namespace std;
int mincostTickets(vector<int>& days, vector<int>& costs) {
    int dp[366];
    dp[0]=0;
    int index=0;
    for(int i=1 ; i<366 ; i++){
    	if( index>=days.size() || i!=days[index]){
    		dp[i]=dp[i-1];
    		continue;
    	}
    	dp[i]=dp[i-1]+costs[0];//for one days
    	dp[i]=min(dp[i] , costs[1]+dp[max(0,i-7)]);//for one weak
    	dp[i]=min(dp[i] , costs[2]+dp[max(0 , i-30)]);//for one month
    	index++;
    }
    return dp[365];
}
int solve(vector<int> &days , vector<int> &costs){
	int dp[30]={};
      int index=0;
	for(int i=days[0] ; i<366 && i<=days.back() ; i++){
		if(index>=days.size() || i!=days[index]){
			dp[i%30]=dp[(i-1)%30];
			continue;
		}
		dp[i%30]=costs[0]+dp[(i-1)%30];
    	dp[i%30]=min(dp[i%30] , costs[1]+dp[max(0,(i-7))%30]);//for one weak
    	dp[i%30]=min(dp[i%30] , costs[2]+dp[max(0 , (i-30))%30]);//for one month
    	index++;
	}
	return dp[days.back()%30];
}
int main(){
	int n;
	cin>>n;
	vector<int> days;
	for(int i=0 ; i<n ; i++){
		int x;cin>>x;
		days.push_back(x);
	}
	vector<int>costs;
	for(int i=0 ; i<3 ; i++){
		int x;cin>>x;
		costs.push_back(x);
	}
	cout<<mincostTickets(days , costs)<<'\n';
}