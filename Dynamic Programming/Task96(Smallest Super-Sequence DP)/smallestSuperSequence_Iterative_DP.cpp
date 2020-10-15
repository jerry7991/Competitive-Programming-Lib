#include<iostream>
#include<cstring>
using namespace std;
int smallestSuperSequence(char str1[], int len1, char str2[], int len2) 
{
	int **dp=new int*[len1+1];
    for (int i = 0; i <=len1; ++i)
    {
    	dp[i]=new int[len2+1];
    }
    //base case
    for (int i = 0; i <=len1; ++i)
    {
    	dp[i][len2]=(len1-i);
    }
    for (int i = 0; i <=len2; ++i)
    {
    	dp[len1][i]=(len2-i);
    }
    for (int i = len1-1; i >=0; --i)
    {
    	for (int j=len2-1 ; j>=0 ; --j)
    	{
    		//check weather first element is same or not
    		if(str1[i]==str2[j])
    		{
    			dp[i][j]=1+dp[i+1][j+1];
    		}else{
    			//find min of both option
    			//option 1 if we include first element of str1 then what will be size of subsequence will be made?
    			//option 2 if we include first element of str2 then what will be size of subsequence will be made?
    			dp[i][j]=1+min(dp[i+1][j],dp[i][j+1]);
    		}
    	}
    }
    return dp[0][0];
}
int main()
{
    char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequence(str1, len1, str2, len2);
    cout<<min_len;
    return 0;
}