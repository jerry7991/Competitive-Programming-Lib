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
int getMaxProfit(struct Actitvity job[]  ,int len)
{
	int *dp=new int[len+1];
	dp[0]=job[0].profit;
	for (int i = 1; i <=len; ++i)
	{
		int including=job[i].profit;
		int lNConflict=-1;
		for (int j=i-1 ; j>=0 ; j--)
		{
			if(job[j].finishTime <= job[i].startTime)
			{
				lNConflict=j;
				break;
			}
		}
		if (lNConflict != -1)
		{
			including	+= dp[lNConflict];
		}
		//excluding
		int excluding=dp[i-1];
		int answer=max(including , excluding);
		dp[i]=answer;
	}
	int answer= dp[len-1];
	delete []dp;
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
	cout<<getMaxProfit(job , n-1);
	cout<<"we need to optimize it because it gives solution in O(N^2)";
}