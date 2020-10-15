#include <iostream>
#include <cstring>
using namespace std;
int findBestBless(char *b1 , char * b2 , int k , int ***dp)
{
	//base case
	if(k==0)
	{
		return 0;
	}
	if(b1[0]=='\0' || b2[0]=='\0')
	{
		return INT_MIN;
	}
	/*
	Before recursive calling first check weather we have solution for this particular 
	bless1.length and bless2.length with correspond to k
	If we have answer then just return and avoid duplicate call so that our recursice tree has as minimum node
	as much possible.. because time complexity will be number of node means how many time function called
	*/
	int m=strlen(b1),n=strlen(b2);
	if(dp[m][n][k]>-1)	//here i am accessing exact m ,n and k that's why i made the size of array m+1,n+1,k+1
	{
		return dp[m][n][k];
	}
	//now we have two candition 
	//1st:- either both b1[0] and b2[0] is same
	int currentAnswer;
	if(b1[0]==b2[0])
	{
		//now we have 3 option 
		int bless=b1[0];
		//Option 1:- skip b1[0] and find bless for rest
		int option1=findBestBless(b1+1 , b2 ,k,dp);
		//option 2:- skip b2[0] and find bless for rest
		int option2=findBestBless(b1 , b2+1 , k,dp);
		//option 3:- pick common i.e. b1[0]==b2[0] i.e. i have picked a char for subsequence to bless
		int option3=bless+findBestBless(b1+1, b2+1,k-1,dp);
		currentAnswer=	max(option1 , max(option2 , option3));
	}else{
		//we have to option
		//skip b1[0] and find bless sequence on rest
		int option1=findBestBless(b1+1 , b2 , k,dp);
		//skip b2[0] and find bless sequence  rest
		int option2=findBestBless(b1 , b2+1  , k,dp);
		currentAnswer=	(option1>option2)?option1 :option2	;
	}
	//before returning the answer we have to store it for which i can use this answer further and avoid duplicate calls
	dp[m][n][k]=currentAnswer;
	return currentAnswer;
	//return dp[m][n][k]; also would work.. Think why and how?
}
int main()
{
	int testCases;
	cin>>testCases;
	while(testCases--)
	{
		char *bless1=new char[100];
		char *bless2=new char[100];
		int k;
		cin>>bless1>>bless2>>k;
		int m=strlen(bless1);
		int n=strlen(bless2);
		int ***dp=new int**[m+1];	//here dp used as memoTable for dp
		for (int i = 0; i <=m; ++i)
		{
			dp[i]=new int*[n+1];
			for (int j = 0; j <=n; ++j)
			{
				dp[i][j]=new int[k+1];
				for (int x = 0; x <=k; ++x)
				{
					dp[i][j][x]=-1;
				}
			}
		}
		int answer=findBestBless(bless1 , bless2 , k , dp);
		if(answer/97>=k)
		 cout<<answer<<endl;
		else
		 cout<<0<<endl;
		//release memory
		for (int i = 0; i <=m; ++i)
		{
			dp[i]=new int*[n+1];
			for (int j = 0; j <=n; ++j)
			{
				delete [] dp[i][j];
			}
		}
		for (int i = 0; i <=m; ++i)
		{
			delete [] dp[i];
		}
		for (int i = 0; i <=m; ++i)
		{
			delete [] dp;
		}
	}
	return 0;
}