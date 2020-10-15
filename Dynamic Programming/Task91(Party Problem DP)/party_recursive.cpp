#include <iostream>
using namespace std;
int getMaxFun(int * partyBudget ,int * partyFun ,int nParty ,int totalBudget)
{
	//base case
	if(nParty<0 || totalBudget==0)
	{
		return 0;
	}
	//now if n-th party's budget is less than our totalBudget then we have two option
	int answer;
	if(totalBudget >=partyBudget[nParty])
	{
		//option 1:- either we can attend that party and store fun correspond to that party
		int option1=partyFun[nParty]+getMaxFun(partyBudget , partyFun , nParty-1 , totalBudget-partyBudget[nParty]);	//our total budget decreased because we have spent mony for n-th party
		//option 2:- or we can skip that party and save our money for future party and look next party with max possibility of fun
		int option2=getMaxFun(partyBudget , partyFun , nParty-1 , totalBudget);
		//return which option has max value
		answer=	(option1>option2)?option1:option2	;
	}else{
		//we n-party's budget is more than our totalBudget then simply we have to just skip that party
		answer	=	getMaxFun(partyBudget , partyFun , nParty-1 , totalBudget)	;
	}
	cout<<nParty<<endl;
	return answer;
}
int main()
{
	while(true)
	{
		int totalBudget , nParty;
		if(totalBudget==0 && nParty==0)
			break;
	cin>>totalBudget>>nParty;
	int *partyBudget=new int[nParty];
	int *partyFun=new int[nParty];
	for (int i = 0; i <nParty; ++i)
	{
		cin>>*(partyBudget+i);cin>>*(partyFun+i);
	}
	cout<<getMaxFun(partyBudget , partyFun , nParty-1 , totalBudget);
	//release memory
	delete [] partyBudget;
	delete [] partyFun;
	}
}