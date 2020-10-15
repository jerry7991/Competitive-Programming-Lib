#include <bits/stdc++.h>
using namespace std;

int solve(int *a,int n,int k,int ***dp,int ongoing)
{ if(n==0)
    return 0;
 if(k==0)
     return 0;
 int ans;
  if(dp[n][k][ongoing]>-1)
      return dp[n][k][ongoing];
    
    int option1=solve(a+1,n-1,k,dp,ongoing);
 if(ongoing)
 {
     int option2=solve(a+1,n-1,k-1,dp,0)+a[0];
     
     dp[n][k][ongoing]=max(option1,option2);
      ans=dp[n][k][ongoing];
 }
 else
 {
     if(k>0)
     {
         int option3=solve(a+1,n-1,k,dp,1)-a[0];
         dp[n][k][ongoing]=max(option1,option3);
          ans=dp[n][k][ongoing];
     }
         
 } 
 return ans;
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int k;
        cin>>k;
        int n;
        cin>>n;
        int *a=new int[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int ***dp= new int**[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int*[k+1];
            for(int j=0;j<=k;k++)
            { 
                dp[i][k]=new int[2];
                  for(int l=0;l<2;l++)
                  dp[i][k][l]=-1;
            }
       }
        int ans=0;//solve(a,n,k,dp,0);
        cout<<ans<<endl;
    }
    return 0;
}
