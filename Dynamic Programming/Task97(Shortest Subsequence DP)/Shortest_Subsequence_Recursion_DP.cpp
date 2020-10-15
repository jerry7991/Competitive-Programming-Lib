#include <bits/stdc++.h>
using namespace std;
#define MAX 1024
int getNShortestSubsequence(char *str1 ,int len1 ,char * str2 ,int len2 , int **dp)
{
	//no uncommon character found
	if(len1==0)
	{
		return MAX;
	}
	//if str2 is empty then min 1 sequence possible
	if (len2<=0)
	{
		return 1;
	}
	if(dp[len1][len2]>-1)
		return dp[len1][len2];
	//other wise let's find first character
	int x;
	for(x=0 ; x<len2 ; x++)
	{
		if(str2[x]==str1[0])
			break;
	}
    if(x==len2)
        return 1;
	//skip first character
	int option1=getNShortestSubsequence(str1+1 , len1-1 , str2 , len2,dp);
	//include first character
	int option2=1+getNShortestSubsequence(str1+1 , len1-1 , str2+x+1 , len2-x-1,dp);
	//store in dp
	int answer=(option1>option2)?option2:option1;
	dp[len1][len2]=answer;
	return answer;
}
int main()
{
	char *str1=new char[1028];
	char *str2=new char[1028];
	cin>>str1>>str2;
	int len1=strlen(str1);
	int len2=strlen(str2);
	int **dp=new int*[len1+1];
	for (int i = 0; i <=len1; ++i)
	{
		dp[i]=new int[len2+1];
		for (int j = 0; j <=len2; ++j)
		{
			dp[i][j]=-1;
		}
	}
	cout<<getNShortestSubsequence(str1 , len1 , str2 , len2 ,dp);
}