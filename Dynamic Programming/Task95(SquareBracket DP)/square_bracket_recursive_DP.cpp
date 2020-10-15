#include <iostream>
using namespace std;
int numberOfTotalValideSquare(int n ,int openning ,int clossing ,bool *memo , int **dp)
{
	if(openning>n || clossing >n)
	{
		return 0;
	}
	if(openning==n && clossing==n)
		return 1;
	if(dp[openning][clossing]>-1)	//because only opennening and clossing changes in recursive solution neither memo nor any thing
    {
        return dp[openning][clossing];
    }
	if(openning==clossing || memo[openning+clossing+1])
	{
		//we have to choose only openning bracket 
		int ans=numberOfTotalValideSquare(n , openning+1 , clossing , memo , dp);
        dp[openning][clossing]=ans;
        return ans;
	}else if(openning==n)
	{
		//we have to choose only clossing bracket
		int ans= numberOfTotalValideSquare(n  , openning , clossing+1 , memo , dp) ;
        dp[openning][clossing]=ans;
        return ans;
	}else{
		//we have both option weather i can choose openning bracket or clossing bracket
		int option1=	numberOfTotalValideSquare(n , openning+1 , clossing , memo , dp);
		int option2=	numberOfTotalValideSquare(n , openning , clossing+1 , memo , dp);
		int ans =option1+option2;
        dp[openning][clossing]=ans;
        return ans;
	}
}
int main()
{
	int dataSet;
	cin>>dataSet;
	while(dataSet--)
	{
		int n , k;
		cin>>n>>k;
		bool *memo=new bool[2*n+1];
		for (int i = 0; i <=2*n; ++i)
		{
			memo[i]=false;
		}
        int **dp=new int*[n+1];
        for(int i=0 ; i<=n ; i++)
        {
            dp[i]=new int[n+1];
            for(int j=0 ; j<=n ; j++)
            {
                dp[i][j]=-1;
            }
        }
		for (int i = 0; i < k; ++i)
		{
			int s;
			cin>>s;
			memo[s]=true;
		}
        if(memo[0])
        {
            //because s exist in between 0<s<=2*n
            cout<<0<<endl;
            continue;
        }
		cout<<numberOfTotalValideSquare(n , 0 , 0 ,	memo,dp)<<endl;
        //release memory
        for(int i=0 ; i<=n ; i++)
        {
            delete [] dp[i];
        }
        delete []dp;
		delete [] memo;
	}
	return 0;
}