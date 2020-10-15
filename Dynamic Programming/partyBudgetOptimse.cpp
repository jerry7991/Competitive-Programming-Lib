#include <iostream>
#define fon(i,n) for(int i=0 ; i<n  ; i++)
using namespace std;
int n , k;
void solve()
{
  int *cost=new int[n];
  int *fun=new int[n];
  fon(i,n) cin>>cost[i]>>fun[i];
  int **dp=new int*[n+1];
  fon(i,n+1)    dp[i]=new int[k+1];
  //base case
  //no party no fun && no money no fun i.e. budget 0
  fon(i,n+1)  dp[i][0]=0;//no party no fun
  fon(i,k+1)  dp[0][i]=0;//no budget no fun
  for(int i=1;i<=n;i++)
    for(int j=1;j<=k ; j++)
    {
      dp[i][j]=dp[i-1][j];
      if(j>=cost[i-1])//if we have a proper budget
        dp[i][j]=max(dp[i][j],fun[i-1]+dp[i-1][j-cost[i-1]]);
    }
    //we want number of party ,so first position where fun ==dp[n][k] will we party number cause no further party includede
  int nParty=0;
  fon(i,k+1)
  if(dp[n][i]==dp[n][k]){
      nParty=i;break;
  }
  int ans=dp[n][k];
  fon(i,n+1) delete []dp[i];delete []dp;
  cout<<nParty<<" "<<ans;
}
int main()
{
  while(true)
  {
    cin>>k>>n;
    if(!n && !k)  return 0;
    solve();
  }
}
