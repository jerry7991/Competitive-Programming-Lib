#include <iostream>
using namespace std;
int getMaxProfit(int *stockPrice ,int nDays ,int nTransaction ,int onGoingT ,int *** dp)
{
	if(nDays==0 || nTransaction == 0)
		return 0;
	//before calling recursivelly first check weather we have a solution for particular nDays , nTransaction , onGoingT or not
	if(dp[nDays][nTransaction][onGoingT]>-1)
	{
		//if we have solution then simply return it
		return dp[nDays][nTransaction][onGoingT];
	}
	//other wise we have to calculate

	//in all case we have an option that for each days we can decide that we wouldn't make any transaction wait for a better stokPrice
	int option1=getMaxProfit(stockPrice+1 , nDays-1 , nTransaction , onGoingT , dp);
	//we shouldn't change onGoingT because we don't make any new transaction and that's also same for nTransaction
	int option2;
	//now if we want to make any transaction then we will have to verify that weather we have any painding transaction or not
	if (onGoingT)
	{
		//if any Painding transaction available then we can only sell that stock and recieve stockPrice ,not buy any new transaction because multiple transaction not allowed
		option2=	stockPrice[0]+getMaxProfit(stockPrice+1 , nDays-1 , nTransaction-1 , 0,dp);
		//nTransaction-1 because we have completed one transaction (that is we have bought and sold that stock) and we don't have any painding transaction that's why onGoingT=0
	}else{
		//if we don't have any painding transaction then we can buy a new transaction
		//but before it we have to check weather we have allowed nTransaction or not
		if(nTransaction>0)
		{
			//now we can only buy stock because we have sold all stock which i bought
			option2	= getMaxProfit(stockPrice+1 , nDays-1 , nTransaction , 1,dp)-stockPrice[0];
			/*
				we can not decrease nTransaction because this transaction just created not completed when it completed , it decreased by one
				set onGoingT=1 because currently we have created a new transaction so we have to take acknowledgement of that for which no new
				transcation can be made during this transaction session.
			*/
		}
	}
	//and which answer has max value that will become my answer for particular nDays , nTransaction , onGoingT
	int answer=	(option1>option2)?option1:option2;
	//before return to this function we should store this answer for particular use
	dp[nDays][nTransaction][onGoingT]=answer;
	return answer;
}
int main()
{
	int testCase;
	cin>>testCase;
	while(testCase--)
	{
		int nTransaction,nDays;
		cin>>nTransaction>>nDays;
		int *stockPrice=new int[nDays];
		for (int i = 0; i < nDays; ++i)
		{
			cin>>*(stockPrice+i);
		}
		int ***dp=new int**[nDays+1];
		for (int j = 0; j <=nDays; ++j)
		{
			dp[j]=new int*[nTransaction+1];
			for (int k = 0; k <=nTransaction; ++k)
			{
				dp[j][k]=new int[2];
				dp[j][k][0]=-1;
				dp[j][k][1]=-1;
			}
		}
		cout<<getMaxProfit(stockPrice , nDays , nTransaction , 0 , dp)<<endl;	//initially set ongoing false i.e. 0

		//release memory
		for (int i = 0; i <=nDays; ++i)
		{
			for (int j = 0; j <=nTransaction; ++j)
			{
				delete [] dp[i][j];
			}
			delete[] dp[i];
		}
		delete [] dp;
	}
}