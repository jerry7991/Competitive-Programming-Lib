#include <iostream>
#define fon(i,n) for(int i=0  ; i< n ; i++)
using namespace std;
int getMinCost(int **cost , int n)
{
	int *dp=new int[1<<n];
	fon(i , 1<<n)
		dp[i]=INT_MAX;
	//base case
	dp[0]=0;
	fon(mask , (1<<n)-1)
	{
		//check number of set bit
		int nSetBit=0;
		int temp=mask;
		while(temp>0)
		{
			if (temp%2==1)
			{
				nSetBit++;
			}
			temp/=2;
		}
		fon(i ,n)
		{
			//we can assigne each person which is equal to nSetBit
			//check weather i-th person allready assigned or not
			int j=i;
			if(!(mask&(1<<i)))
			{
				//we can assigne dp[mask|(1<<i)] with the help of dp[mask]
				dp[mask | (1<<i)]=min(dp[mask | (1<<i)] , dp[mask]+cost[nSetBit][i]);
			}
		}
	}
	int answer=dp[(1<<n)-1];
	delete []dp;
	return answer;
}
int main()
{
int n;
cin>>n;
int **cost=new int*[n];
fon(i , n)
{
	cost[i]=new int[n];
	fon(j , n)
	{
		cin>>cost[i][j];
	}
}
cout<<getMinCost(cost , n);
//release memory
fon(i ,n )
	delete []cost[i];
delete []cost;
}