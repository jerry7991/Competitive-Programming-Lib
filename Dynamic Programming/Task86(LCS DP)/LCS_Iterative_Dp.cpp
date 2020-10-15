#include <iostream>
#include <cstring>
using namespace std;
int lcs_iteratively(char *s1 ,char *s2)
{
	int m=strlen(s1);
	int n=strlen(s2);
	//let's make dp array
	int **dp=new int*[m+1];
	for (int i = 0; i <=m; ++i)
	{
		dp[i]=new int[n+1];
	}
	//base case 1:-
		//when both string have null value i.e. length 0;
		dp[0][0]=0;
	//base case 2:-
		//when s1 has null value only i.e. length 0;
		for (int i = 0; i <=n; ++i)
		{
			dp[0][i]=0;
		}
	//base case 3:-
		//when s2 has null value only i.e. length 0;
		for (int i = 0; i <=m; ++i)
		{
			dp[i][0]=0;
		}
	//let's fill dp array with the help of our 3 base case
		for (int i = 1; i <=m; ++i)
		{
			for (int j = 1; j <=n; ++j)
			{
				//first condition if first character of both string is equal
				if(s1[m-i]==s2[n-j])
				{
					dp[i][j] =1+dp[i-1][j-1];
				}else{
					/*	we have to two choice that weather we can include first character
						of s1 in our subsequence or first character of s2
						and which subsequenc has maximum length that's mine answer of (i,j)
					*/
					dp[i][j]=	(	dp[i-1][j] <dp[i][j-1]	)?dp[i][j-1]:dp[i-1][j];
				}
			}
		}
		//after filling the dp array my answer is dp[m][n] but first store ans and remove memory what i am alocated
		int answer=dp[m][n];
		for (int i = 0; i <=m; ++i)
		{
			delete [] dp[i];
		}
		delete [] dp;
		return answer;
}
int main()
{
	char * s1=new char[1000];
	char * s2=new char[1000];
	cin>>s1>>s2;
	cout<<lcs_iteratively(s1,s2);
	//release memory
	delete []s1;
	delete []s2;
	return 0;
}