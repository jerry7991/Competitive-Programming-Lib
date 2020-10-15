#include <iostream>
#include <string>
using namespace std;
int editDistanceVal(string str1 , string str2 , int l , int m ,int nStr1,int nStr2)
{
	if (l==nStr1 && m==nStr2)
	{
		return 0;
	}
	if (l==nStr1)
	{
		return nStr2-m;
	}
	if (m==nStr2)
	{
		return nStr1-l;
	}
	int ans=0;
	if (str1[l]==str2[m])
	{
		ans=editDistanceVal(str1 , str2 , l+1 ,m+1,nStr1 , nStr2);
	}else{
		//delete unmatched character in str2
		int opt1=1+editDistanceVal(str1 , str2 , l+1 ,m,nStr1 , nStr2);
		//replace a character with matching char
		int opt2=1+editDistanceVal(str1 , str2 , l+1 ,m+1,nStr1 , nStr2);
		//insert matched character
		int opt3=1+editDistanceVal(str1 , str2 , l ,m+1,nStr1 , nStr2);
		ans=min(opt1,min(opt2,opt3));
	}
	return ans;
}
int getEdit(string str1 , string str2)
{
	int l=str1.length();
	int m=str2.length();
	int **dp=new int*[l+1];
	for (int i = 0; i <=l; ++i)
	{
		dp[i]=new int[m+1];
		for(int j=0 ; j<=m;j++)
			dp[i][j]=0;
	}
	//base case
	//if one string is null then edit distance will be size of other
	for (int i = 1; i <=l; ++i)
    {
        dp[i][0]=i;
    }
    for (int i = 1; i <=m; ++i)
    {
        dp[0][i]=i;
    }
	//if both string is null then edit value will be 0
	dp[0][0]=0;
	for (int i = 1; i <=l; ++i)
	{
		for(int j=1;j<=m;j++)
		{
			if (str1[l-i]==str2[m-j])
			{
				dp[i][j]=dp[i-1][j-1];
			}else{
				int ans=min(dp[i-1][j-1],min(dp[i-1][j] ,dp[i][j-1]));
				dp[i][j]=ans+1;
			}
		}
	}
	return dp[l][m];
}
int main()
{
	string str1,str2;
	cin>>str1;
	cin>>str2;
	cout<<editDistanceVal(str1 , str2 , 0, 0, str1.length()  , str2.length())<<endl;
	cout<<getEdit(str1,str2)<<endl;
}