#include <iostream>
#include <string>
#define ll long long int
using namespace std;
long long int solve(string str1)
{
    string str2="ROR";
	int l=str1.size();int m=str2.size();
    long long int **dp=new long long int*[m+1];
    for(int i=0 ; i<=m ; i++)
    {
        dp[i]=new long long int[l+1];
        for(int j=0 ; j<=l;j++)
            dp[i][j]=0;
    }
    for (int i = 0; i <=m; ++i)
    {
        dp[i][l]=0;
    }
    for (int i = 0; i <=l; ++i)
    {
        dp[m][i]=1;//by default null will be common value for both
    }
    dp[m][l]=1;
    for (int i = m-1; i >=0; --i)
    {
        for(int j=l-1;j>=0;--j)
        {
            dp[i][j]=dp[i][j+1];
            if(str1[j]==str2[i])
                dp[i][j]+=dp[i+1][j+1];
        }
    }
    // for (int i = 0; i <=m; ++i)
    // {
    //     for(int j=0 ; j<=l ; ++j)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    long long int ans=dp[0][0];
    cout<<endl;
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