#include <iostream>
using namespace std;
int getMinSalary(int *cSalary ,int * aSalary ,int n , int A_C_difference)
{
	if(n==0)
		return 0;
	//now we have to check weather our assistance and captain difference is 0 or not
	if(A_C_difference==0)
	{
		//then we have no choice to pick pilot as a captain because no captain allowed without their assistace so 
		//first pick assistant and then pick captain for that assistant
		int option1=aSalary[0]+getMinSalary(cSalary+1 , aSalary+1 , n-1 , 1);
		/*
			cSalary+1 because for aSalary[0]-th assistant their captain age should be greater then that
			A_C_difference=1; because currently i picked an assistance so A_C_difference become one
		*/
		return option1;
	}
	else if(A_C_difference==n)
	{
		//if A_C_difference==n meanse we have required n captain because a-c=n i.e. a=c+n;
		//so for provide each assistance we required captain..
		int option2= cSalary[0]+getMinSalary(cSalary+1 , aSalary+1 , n-1 , A_C_difference-1);
		return option2;
	}else{
		//we have both option for n-th pilot ;either we can choose them as a captain or as an assitance
		int asCaptain= cSalary[0]+getMinSalary(cSalary+1 , aSalary+1 , n-1 , A_C_difference-1);
		//A_C_difference-1 because our difference of assistance-captain decrease due to increase in captain i.e. a-(c+1)=(a-c)-1=A_C_difference-1

		//choose as a assistance
		int asAssistant= aSalary[0]+getMinSalary(cSalary+1 , aSalary+1 ,n-1 , A_C_difference+1);
		//A_C_difference+1 because our assistance increased :- (a+1)-c=(a+c)-1=A_C_difference+1
		
		return (	(asCaptain<asAssistant)?asCaptain :asAssistant	);
	}
}	
int main()
{
	int x;
	cin>>x;
	int *cSalary=new int[x];
	int *aSalary=new int[x];
	for (int i = 0; i < x; ++i)
	{
		cin>>cSalary[i]>>aSalary[i];
	}
	cout<<getMinSalary(cSalary , aSalary , x , 0);//0 because intially our difference between captain and assistance 0
}