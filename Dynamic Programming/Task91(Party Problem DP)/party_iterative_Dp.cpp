#include <iostream>
using namespace std;
struct Party
{
	int entryFee;
	int fun;
};
int main()
{
	while(true)
	{
		int totalBudget,nParty;
		cin>>totalBudget>>nParty;
		if(totalBudget==0 && nParty==0)
			return 0;
		Party *partySchedule=new Party[nParty];
		for (int i = 0; i < nParty; ++i)
		{
			cin>>partySchedule[i].entryFee;
			cin>>partySchedule[i].fun;
		}
		Party **dp=new Party*[nParty+1];
		for (int i = 0; i <=nParty; ++i)
		{
			dp[i]=new Party[totalBudget+1];
		}
		for (int i = 0; i <=nParty; ++i)
		{
			dp[i][0].entryFee=0;
			dp[i][0].fun=0;
		}
		for (int i = 0; i <=totalBudget; ++i)
		{
			dp[0][i].entryFee=0;
			dp[0][i].fun=0;
		}
		for (int i = 1; i <=nParty; ++i)
		{
			for (int j = 1; j <=totalBudget; ++j)
			{
				dp[i][j].entryFee=dp[i-1][j].entryFee;
				dp[i][j].fun=dp[i-1][j].fun;
				if( j>=partySchedule[i-1].entryFee )
				{
					if(	dp[i-1][j].fun < dp[i-1][j-partySchedule[i-1].entryFee].fun	)
					{
						dp[i][j].fun=partySchedule[i-1].fun+dp[i-1][j-partySchedule[i-1].entryFee].fun;
						dp[i][j].entryFee=partySchedule[i-1].entryFee+dp[i-1][j-partySchedule[i-1].entryFee].entryFee;
					}
				}
			}
		}
		cout<<dp[nParty][totalBudget].fun<<" "<<dp[nParty][totalBudget].entryFee;
	}
}