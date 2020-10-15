#include<iostream> 
using namespace std;
struct Activity
{
	int weight;
	int value;
};
int getMaxValue(Activity * job , int n , int maxWeight , int **dp)
{
	if(maxWeight==0)
		return 0;
	if(n<0)
		return 0;
	if(dp[n][maxWeight]>-1)
		return dp[n][maxWeight];
	//if n-th element allowed to take into knapsack then then we have two option
	if (job[n].weight<=maxWeight)
	{
		//either we can take first job into knapsack or not
		int option1=job[n].value+getMaxValue(job , n-1 , maxWeight-job[n].weight ,dp);
		int option2=getMaxValue(job , n-1 , maxWeight ,dp);
		int answer=max(option1 , option2);
		dp[n][maxWeight]=answer;
		return answer;
	}else{
		int answer=getMaxValue(job , n-1 , maxWeight , dp);
		dp[n][maxWeight]=answer;
		return answer;
	}
}
int main()
{
	int nItems;
	cin>>nItems;
	Activity * job=new Activity[nItems];
	for (int i = 0; i < nItems; ++i)
	{
		cin>>job[i].weight;
	}
	for (int i = 0; i < nItems; ++i)
	{
		cin>>job[i].value;
	}
	int maxWeight;
	cin>>maxWeight;

	int **dp=new int*[nItems+1];
	for (int i = 0; i <=nItems; ++i)
	{
		dp[i]=new int[maxWeight+1];
		for (int j = 0; j <=maxWeight; ++j)
		{
			dp[i][j]=-1;
		}
	}
	cout<<getMaxValue(job , nItems-1 , maxWeight , dp)	;									
	return 0;
}