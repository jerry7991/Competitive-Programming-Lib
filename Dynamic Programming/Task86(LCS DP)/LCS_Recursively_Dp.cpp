#include <iostream>
#include <cstring>
using namespace std;
int lcsHelper(char *s1 ,char* s2 ,int m ,int n , char **dp)
{
	if(m==0 || n==0)
		return 0;
	//before going to recursive call we should check i.e.
	//either we have answer for (m,n) or not
	if (dp[m][n]>-1)	//we are accessing m and n that's why we need of array m+1 and n+1
	{
		return dp[m][n];
	}
	//if don't have answer then solve
	int answer;
	if (s1[0]==s2[0])
	{
		//i.e. first case both string 0-th element is equal
		answer=1+lcsHelper(s1+1 , s2+1 ,m-1 , n-1,dp);
	}else
	{
		//option1 :- pick first char of s1 as subsequence 
		int option1=lcsHelper(s1+1 , s2 , m-1 , n ,dp);
		//option2 :- pick first char of s2 as subsequence
		int option2=lcsHelper(s1 , s2+1 , m ,n-1 ,dp);
		answer=(option1>option2)?option1:option2;
	}
	//before returnig to base function first store the answer what i got for (m,n)
	dp[m][n]=answer;
	return answer;
	
}
int lcs(char * s1 , char *s2)
{
	int m=strlen(s1);
	int n=strlen(s2);
	char **dp=new char*[m+1];
	for (int i = 0; i <= m; i++)
	{
		dp[i]=new char[n+1];
		for (int j = 0; j <=n; j++)
		{
			dp[i][j]=-1;	//we can't store 0 because 0 is the output for 
			//any string or both has 0 element then lcs will be 0
		}
	}
	int answer=lcsHelper(s1 ,s2 , m , n , dp);
	//release memory
	for (int i = 0; i <=m; i++)
	{
		delete [] dp[i];
	}
	delete [] dp;
	return answer;
}
int main()
{
	char *s1=new char[100];
	char *s2=new char[100];
	cin>>s1>>s2;
	cout<<lcs(s1,s2)<<endl;
	//release memory
	delete []s1;
	delete []s2;
	cout<<"This is much better time complexity was O(2*N) and Space complexity O(N^2) where is N=(length of first string * length of second string";
	return 0;
}