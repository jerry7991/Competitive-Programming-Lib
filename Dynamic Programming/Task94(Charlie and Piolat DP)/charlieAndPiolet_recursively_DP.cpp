#include <iostream>
using namespace std;
int getMinSalary(int *cSalary ,int * aSalary ,int n ,int A_C_Difference ,int ** dp)
{
	if(n==0)
		return 0;
	//check weather we have any solution for particular n and A_C_Difference 
	if(	dp[A_C_Difference][n]>-1 )
	{
		return dp[A_C_Difference][n];
	}
	//other wise let's solve it 
	if(A_C_Difference==0)
	{
		//we can't make any new captain because we can not make a new captain without any available assistance
		int option1=aSalary[0]+getMinSalary(cSalary+1 , aSalary+1 , n-1 ,A_C_Difference+1, dp);
		//and before returnnig the solution for this A_C_Difference , n we should store to use further
		dp[A_C_Difference][n]=option1;
		return option1;
	}else if(A_C_Difference==n)
	{
		//we can pick a pilot as captain only because we have allready extra n assistance
		int option2= cSalary[0]+getMinSalary(cSalary+1 , aSalary+1 , n-1 , A_C_Difference-1 , dp);
		dp[A_C_Difference][n]=option2;
		return option2;
	}else{
		//we can pick as a captain and as a pilot both
		int asCaptain=cSalary[0]+getMinSalary(cSalary+1 , aSalary+1 , n-1 , A_C_Difference-1 , dp);

		int asAssistance=aSalary[0]+getMinSalary(cSalary+1 , aSalary+1 , n-1 , A_C_Difference+1 , dp);

		int answer=	(	(asCaptain>asAssistance )?asAssistance :asCaptain	);
		dp[A_C_Difference][n]=answer;
		return answer;
	}
}
int main()
{
	int n;
	cin>>n;
	int *cSalary=new int[n];
	int *aSalary=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>*(cSalary+i);
		cin>>*(aSalary+i);
	}
	int **dp=new int*[n/2+1];
	for (int i = 0; i <=n/2; ++i)
	{
		dp[i]=new int[n+1];
		for (int j = 0; j <=n ; ++j)
		{
			dp[i][j]=-1;
		}
	}
	cout<<getMinSalary(cSalary , aSalary , n , 0 , dp);
	 //release memory
    for(int i=0 ; i<=n/2 ; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    delete [] cSalary;
    delete [] aSalary;
    return 0;
}