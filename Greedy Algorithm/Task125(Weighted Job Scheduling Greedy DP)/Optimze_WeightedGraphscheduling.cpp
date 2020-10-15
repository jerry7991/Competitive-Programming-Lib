#include <iostream>
#include <algorithm>
using namespace std;
struct  Actitvity
{
	int startTime;
	int finishTime;
	int profit;
};
bool compare(struct Actitvity  job1 , struct Actitvity job2)
{
	//sort according to their finishTime

	return (job1.finishTime<job2.finishTime);
}
int binarySearch(struct Actitvity job[] , int start , int end , int currentStartTime)
{
	if(start>end)
	{
		return -1;
	}
	int mid=(start+end)/2;
	if (job[mid].finishTime>currentStartTime)
	{
		return binarySearch(job , start , mid-1 , currentStartTime);
	}
	else if(job[mid].finishTime<=currentStartTime && job[mid+1].finishTime <=currentStartTime)
	{
		return binarySearch(job , mid+1 , end , currentStartTime);
	}else{
		return mid;
	}
}
int getMaxProfit(struct Actitvity *job  , int len)
{
	int *dp=new int[len];
	//our base case
	dp[0]=job[0].profit;
	for (int i = 1; i <len; ++i)
	{
		int including=job[i].profit;
		//search for  first non conflict job
		int si=0;
		int ei=i-1;
		int lNConflict=binarySearch(job , si ,ei , job[i].startTime);
		if (lNConflict!=-1)
		{
			including += dp[lNConflict];
		}
		int excluding=dp[i-1];
		dp[i]=max(including , excluding);
	}
	int answer=dp[len-1];
	return answer;
}
int main()
{
	int n;
	cin>>n;
	Actitvity *job=new Actitvity[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>job[i].startTime;
		cin>>job[i].finishTime;
		cin>>job[i].profit;
	}
	sort(job , job+n,compare);
	cout<<getMaxProfit(job , n);
	// cout<<"we need to optimize it because it gives solution in O(N^2)";
}