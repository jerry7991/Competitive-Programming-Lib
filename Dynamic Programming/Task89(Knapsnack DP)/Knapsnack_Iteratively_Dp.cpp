#include <iostream>
using namespace std;
int knapsnack(int *weight ,int *value ,int n ,int kWeight)
{
	int **dp=new int*[n+1];
	for (int i = 0; i <=n; i++)
	{
		dp[i]=new int[kWeight+1];
	}

	//base case:-
	//base case 1:-
		//if kWeight is 0 then cann't put a single item in out knapsnack
		for (int i = 0; i <=n; i++)
		{
			dp[i][0]=0;
		}
	//base case 2:-
		//if n is 0 then we have null item i.e. 0 to put into knapsnack
		for (int i = 0; i <=kWeight; i++)
		{
			dp[0][i]=0;
		}
	//now let's start fill the dp with the help of base case and recursive relation
		for (int i = 1; i <=n; i++)
		{
			for (int w = 0; w <=kWeight; w++)
			{
				//in best case or worst case we check about to not include of any item
				dp[i][w]=dp[i-1][w];//ignore i-th item and save knapsnack space
				if(weight[i-1]<=w)
				{
					//then check what happen when we put i-th element in knapsnack
					dp[i][w]=max(	dp[i][w] , value[i-1]+dp[i-1][w-weight[i-1]]	);
				}
			}
		}
		int ans=dp[n][kWeight];
	//release memory
	for (int i = 0; i <=n; ++i)
	{
		delete [] dp[i];
	}
	delete []dp;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int *weight=new int[n];
	int *value=new int[n];
	for (int i = 0; i <n; ++i)
	{
		cin>>weight[i];
	}
	for (int i = 0; i <n; ++i)
	{
		cin>>value[i];
	}
	int kWeight;
	cin>>kWeight;
	cout<<knapsnack(weight , value , n , kWeight)<<endl;
	cout<<"\n space complexity is O(N*Max weight) we can do O(2*Max weight) because at a time we need only two rows"<<endl;
	return 0;
}