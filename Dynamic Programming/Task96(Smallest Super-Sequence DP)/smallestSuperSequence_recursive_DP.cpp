#include<iostream>
#include<cstring>
using namespace std;
int smallestSuperSequence(char *str1,int len1, char * str2, int len2 , int **dp)
{
	//base case
	if(len1==0 &&  len2!=0)
	{
		return len2;
	}
	if(len1!=0 && len2==0)
	{
		return len1;
	}
	if (len1==0 && len2==0)
	{
		return 0;
	}
	if(dp[len1][len2]>-1)
	{
		return dp[len1][len2];
	}
	//check weather 0-th element is same
	if(str1[0]==str2[0])
	{
		//take that common letter
		int answer=1+smallestSuperSequence(str1+1 , len1-1 , str2+1 , len2-1,dp);
		dp[len1][len2]=answer;
		return answer;
	}else{
		int answer;
		//we have two option either i can pick first element of str1 or
		int option1=1+smallestSuperSequence(str1+1 , len1-1 ,str2 , len2,dp);
		//we can pick first element of str2
		int option2=1+smallestSuperSequence(str1 , len1 , str2+1 ,len2-1,dp);
		answer= (	option1>option2	)?option2 :option1;
		dp[len1][len2]=answer;
		return answer;
	}
}
int main()
{
    char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **dp=new int*[len1+1];
    for (int i = 0; i <=len1; ++i)
    {
    	dp[i]=new int[len2+1];
    	for (int j = 0; j <=len2; ++j)
    	{
    		dp[i][j]=-1;
    	}
    }
    int min_len = smallestSuperSequence(str1, len1, str2, len2 ,dp);
    cout<<min_len;
    return 0;
}
