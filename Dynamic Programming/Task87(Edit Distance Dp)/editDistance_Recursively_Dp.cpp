#include <iostream>
#include <cstring>
using namespace std;
int editDistance(char *s1 , char *s2 ,int **dp)
{
	int m=strlen(s1);
	int n=strlen(s2);
	if(m==0 && n!=0)
		return n;
	if(m!=0 && n==0)
		return m;
	if(m==0 && n==0)
		return 0;
	if(dp[m][n]>-1)
	{
		return dp[m][n];
	}
	int answer;
	//if first element of both char array is same just step up
	if(s1[0]==s2[0])
	{
		answer= editDistance(s1+1 , s2+1,dp);
	}else{
		//option 1:- delete first element and look for rest of char array
		int option1=1+editDistance(s1+1,s2,dp);
		//option 2:- assign first element of s1 with first element of s2
		int option2=1+editDistance(s1+1,s2+1,dp);
		//option 3:- add s2[0] in front of s1[0] 
		int option3=1+editDistance(s1,s2+1,dp);

		answer=min(option1 , min(option2 , option3));
	}
	//before returning save it;
	dp[m][n]=answer;
	return answer;
}
int main()
{
	char s1[100],s2[100];
	cin>>s1>>s2;
	//let's make an dp array
	int m=strlen(s1);
	int n=strlen(s2);
	int ** dp=new int*[m+1];
	for (int i = 0; i <=m; ++i)
	{
		dp[i]=new int[n+1];
		for (int j = 0; j <=n; ++j)
		{
			dp[i][j]=-1;
		}
	}
	cout << editDistance(s1,s2,dp) << endl;
	//release memory
	for (int i = 0; i <=m; ++i)
	{
		delete [] dp[i];
	}
	delete []dp;
	cout<<"\n Time complexity would be nearly O(2*N) due to first fill the array and and come back to return\n";
	return 0;
}