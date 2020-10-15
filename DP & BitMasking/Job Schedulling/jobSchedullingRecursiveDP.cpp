#include <iostream>
#define fon(i,n) for(int i=0 ; i<n  ; i++)
using namespace std;
int getMinCost(int **cost , int n , int *dp , int mask , int person)
{
	if (person>=n)
	{
		//we have assigned all the job just return
		return 0;
	}
	//before solve the problem for particular mask we need to check weather we have solution
	//or not
	if (dp[mask]!=INT_MAX)
	{
		//if we have allready solution then just return
		return dp[mask];
	}
	//if we haven't
	//solve if
	int minimum=INT_MAX;
	fon(i , n)
	{
		//check weather i-th person assigned a job or not
		if ((mask&(1<<i))==0)
		{
			//not yet assigned then assigned  current i-th job to current person
			int ans=getMinCost(cost , n ,dp , mask| (1<<i) , person+1)+cost[person][i];
			minimum=(minimum>ans)?ans:minimum;
		}
	}
	//before returning the solution we need to save it
	dp[mask]=minimum;
	return minimum;
}
int main()
{
	int n;
	cin>>n;
	int **cost=new int*[n];
	fon(i , n)
	{
		cost[i]=new int[n];
		fon(j,n)
		 cin>>cost[i][j];
	}
	//we need a dp array of size 2^n
	int *dp=new int[1<<n];
	fon(i , 1<<n)
		dp[i]=INT_MAX;
	cout<<getMinCost(cost , n , dp , 0 , 0)<<endl;
	//dp[0] has the output
	 fon(i , 1<<n)
	 	cout<<dp[i]<<" ";
	fon(i , n)
	 delete [] cost[i];
	delete []cost;
	delete []dp;
}
/*
4
10 2 6 5
1 15 12 8
7 8 9 3
15 13 4 10
o/p=10
*/