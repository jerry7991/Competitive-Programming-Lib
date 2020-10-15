#include <bits/stdc++.h>
using namespace std;
int mincostTickets(vector<int>& days  , vector<int>&costs){
	//let's store the day in unordered_set for searching in O(1)
	unordered_set<int> travel;
	for(int i=0 ; i<days.size();i++) travel.insert(days[i]);
	//max possible days is 365
	int dp[366]={};
	for(int i=1 ; i<366 ; i++){
		if(travel.find(i)==travel.end()){
			//that's means this day is not for travel
			dp[i]=dp[i-1];
		}else{
			//this day is for travelling
			int oneDayPass=dp[i-1]+costs[0];
			int oneWeekPass=dp[max(0 , i-7)]+costs[1];
			int oneMonthPass=dp[max(0 , i-30)]+costs[2];
			//now have to store the min
			dp[i]=min({oneDayPass , oneMonthPass , oneWeekPass});
		}
	}
	return dp[365];
}
int mincostTicketsOptimised(vector<int>& days  , vector<int>&costs){
	//let's store the day in unordered_set for searching in O(1)
	unordered_set<int> travel;
	for(int i=0 ; i<days.size();i++) travel.insert(days[i]);
	//max possible days is not necessary 365 because at a time we have requirement of last 30 days only
	int dp[30]={};
	for(int i=days.front() ; i<=days.back();i++){
		if(travel.find(i)==travel.end()){
			dp[i%30]=dp[(i-1)%30];
		}else{
			int Day1Pass=dp[(i-1)%30]+costs[0];
			int Day7Pass=dp[max(0,(i-7)%30)]+costs[1];
			int Day30Pass=dp[max(0,(i-30)%30)]+costs[2];
			dp[i%30]=min({Day1Pass , Day7Pass , Day30Pass});
		}
	}
	int ans=dp[days.back()%30];
	return ans;
}
int main(){
	int n;
	cin>>n;
	vector<int> days;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		days.push_back(x);
	}
	int m;cin>>m;
	vector<int>costs;
	for(int i=0 ; i<m ; i++){
		int x;
		cin>>x;
		costs.push_back(x);
	}
	cout<<mincostTickets(days , costs);
}