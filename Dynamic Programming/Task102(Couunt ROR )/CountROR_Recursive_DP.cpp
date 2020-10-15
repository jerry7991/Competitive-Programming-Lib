#include <iostream>
using namespace std;
long long count(string str1 , string str2 , long long len1 , long long len2 , long long **dp)
{
	if(len1==0  ||len1<len2)
		return 0;
	if(len2==0)
		return 1;
	if(len1==1 && len2==1)
	{
		return (str1[len1]==str2[len2]);
	}
	if (dp[len1][len2]!=-1)
	{
		return dp[len1][len2];
	}
	long long answer;
	if (str1[len1-1]==str2[len2-1])
	{
		long option1=count(str1 , str2 , len1-1  , len2-1 ,dp);
		long option2=count(str1 , str2 , len1-1 , len2 , dp);
		answer=(option1+option2);
	}else{
		answer= count(str1 , str2 , len1-1 , len2 , dp);
	}
		dp[len1][len2]=answer;
		return answer;
}
int main()
{
	string X ;cin>>X; 
	string Y = "ROR";
	long long **dp=new long long*[X.size()+1];
	for (long long i = 0; i <= X.size(); ++i)
	{
		dp[i]=new long long [Y.size()+1];
		for (long long j = 0; j <=Y.size(); ++j)
		{
			dp[i][j]=-1;
		}
	}
	long long m=X.size();
	long long n=Y.size();
	cout << count(X, Y, m, n , dp);
	// for (long long i = 0; i <= X.size(); ++i)
	// {
	// 	for (long long j = 0; j <=Y.size(); ++j)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}