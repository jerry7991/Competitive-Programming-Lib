#include <iostream>
#include <string>
using namespace std;
long long int geTnWay(string str1 , string str2 , int s1,int s2 , int l , int m,long long int **dp)
{
	//base case
	if (s1==l && s2==m)
	{
		return 1;
	}
	if (s1==l)
	{
		return 0;
	}
	if (s2==m)
	{
		return 1;
	}
    if(dp[s2][s1]!=-1)
        return dp[s2][s1];
	long long int ans=0;
	 if(str1[s1]!=str2[s2])
	{
		ans=geTnWay(str1 , str2 , s1+1 , s2 , l ,m,dp);
	}else{
		int opt1=geTnWay(str1 , str2 , s1+1 ,s2 , l ,m,dp);
		int opt3=geTnWay(str1 , str2 , s1+1 ,s2+1 , l ,m,dp);
		ans=opt1+opt3;
	}
    dp[s2][s1]=ans;
	return ans;
}
long long int solve(string str1)
{
    string str2="ROR";
	int l=str1.size();int m=str2.size();
    long long int **dp=new long long int*[m+1];
    for(int i=0 ; i<=m ; i++)
    {
        dp[i]=new long long int[l+1];
        for(int j=0 ; j<=l;j++)
            dp[i][j]=-1;
    }
	long long int ans= geTnWay(str1 , str2 , 0 , 0 ,l , m,dp);
    for(int i=0  ; i<=m ; i++)
    {
        delete []dp[i];
        }
    delete []dp;
    return ans;
}
int main()
{
	string str;
	cin>>str;
	cout<<solve(str);
	return 0;
}