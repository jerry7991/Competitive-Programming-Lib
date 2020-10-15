#include <iostream>
using namespace std;
int getProfit(int *stockPrice , int days , int nTransaction , int onGoingTransaction)
{
	if(days<0 || nTransaction==0)
		return 0;
	int option1=getProfit(stockPrice+1 , days-1 , nTransaction , onGoingTransaction);
	int option2;
	if(onGoingTransaction)
	{
		//I can only sell our stock not buy
		 option2=getProfit(stockPrice+1 ,days-1 , nTransaction-1 , 0)+stockPrice[0];
	}else{
		//if k>0 then i can start the new transaction
		if(nTransaction>0)
		{
			//we can transaction and because we have no running transaction so we can buy new transaction	
			option2=getProfit(stockPrice+1 , days-1 ,nTransaction ,1)-stockPrice[0];//1 because i made transaction
		}
	}
	return max(option1 , option2);
}
int main()
{
	int testCases;
	cin>>testCases;
	while(testCases--)
	{
	int days,nTransaction;
	cin>>nTransaction>>days;
	int *stockPrice=new int[days];
	for (int i = 0; i < days; ++i)
	{
		cin>>stockPrice[i];
	}
	cout<<getProfit(stockPrice , days-1 , nTransaction , 0)<<endl;
	}
}