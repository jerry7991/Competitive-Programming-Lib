#include <iostream>
#include <string>
using namespace std;
int LCS(string str1 , string str2 , int l , int m , int nStr1 , int nStr2)
{
	if (l==nStr1 || m==nStr2)
	{
		return 0;
	}
	int ans;
	if (str1[l]!=str2[m])
	{
		int opt1=LCS(str1 , str2 , l+1,m,nStr1 , nStr2);
		int opt2=LCS(str1 , str2 , l,m+1,nStr1 , nStr2);
		ans=(opt1>opt2)?opt1:opt2;
	}else{
		int opt1=1+LCS(str1 , str2 , l+1,m+1,nStr1 , nStr2);
		ans=opt1;
	}
	return ans;
}
int lcsDpRec(string  str1 ,string str2  ,int l ,int m ,int nStr1 ,int nStr2 , int **dp)
{
	if (l==nStr1 || m==nStr2)
	{
		return 0;
	}
	if (dp[l][m]!=-1)
	{
		return dp[l][m];
	}
	int ans=0;
	if (str1[l]!=str2[m])
	{
		int opt1=lcsDpRec(str1 , str2 , l+1 , m , nStr1 , nStr2 , dp);
		int opt2=lcsDpRec(str1 , str2 , l , m+1 , nStr1 , nStr2 , dp);
		ans=(opt1>opt2)?opt1:opt2;
	}else{
		ans=1+lcsDpRec(str1 , str2 , l+1 , m+1 , nStr1 , nStr2 , dp);
	}
	dp[l][m]=ans;
	return ans;
}
int lcs(string  str1 ,string str2)
{
	int nStr1=str1.length();
	int nStr2=str2.length();
	int **dp=new int*[nStr1+1];
	for (int i = 0; i <=nStr1; ++i)
	{
		dp[i]=new int[nStr2+1];
		for(int j=0;j<=nStr2;j++)
			dp[i][j]=-1;
	}
	int ans=lcsDpRec(str1 , str2  , 0 , 0 ,nStr1 , nStr2,dp);
	for (int i = 0; i <=nStr1; ++i)
	{
		delete []dp[i];
	}
	delete []dp;
	return ans;
}
int lcsIterative(string str1 , string str2)
{
	int l=str1.length();
	int m=str2.length();
	int **dp=new int*[l+1];
	for(int i=0 ; i<=l;i++)
	{
		dp[i]=new int[m+1];
		for(int j=0 ; j<=m ; j++)
			dp[i][j]=0;
	}
	dp[l][m]=0;
	for(int i=l-1 ; i>=0 ; i--)
	{
		for(int j=m-1 ; j>=0 ; j--)
		{
			if (str1[i]==str2[j])
			{
				dp[i][j]=1+dp[i+1][j+1];
			}else{
				dp[i][j]=max(dp[i][j+1] , dp[i+1][j]);
			}
		}
	}
	return dp[0][0];
}
int main()
{
	string str1,str2;
	cin>>str1;
	cin>>str2;
	cout<<LCS(str1 , str2 , 0 , 0 , str1.length() , str2.length())<<endl;
	cout<<lcs(str1 , str2)<<endl;
	cout<<lcsIterative(str1 , str2)<<endl;
}