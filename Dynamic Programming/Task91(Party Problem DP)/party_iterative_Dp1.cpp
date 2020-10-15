#include <iostream>
using namespace std;
int main()
{
	
	while(true)
    {
    int budget,nParty;
	cin>>budget>>nParty;
        if(budget==0 && nParty==0)
            return 0;
        int *entryFee=new int[nParty];
	int *fun=new int[nParty];
	for (int i = 0; i <nParty; ++i)
	{
		cin>>entryFee[i];
		cin>>fun[i];
	}
	int **dp=new int*[nParty+1];
	for (int i = 0; i <=nParty; ++i)
	{
		dp[i]=new int[budget+1];
	}
	for (int i = 0; i <=nParty; ++i)
	{
		dp[i][0]=0;
	}
	for (int i = 0; i <=budget; ++i)
	{
		dp[0][i]=0;
	}
	for(int i=1 ; i<=nParty ; i++)
	{
		for (int j = 1; j <=budget; ++j)
		{
			dp[i][j]=dp[i-1][j];
			if(entryFee[i-1]<=j)
			{
				dp[i][j]=max(dp[i][j] ,fun[i-1]+dp[i-1][j-entryFee[i-1]]);
			}
		}
	}
	int f=0;
	int b=0;
	for (int i = 0; i <=budget; ++i)
	{
		if(dp[nParty][i]>f)
		{
			f=dp[nParty][i];
			b=i;
		}
	}
	//release memory
	for (int i = 0; i <=budget; ++i)
	{
		/* code */
	}
	cout<<b<<" "<<f<<endl;
    }
}