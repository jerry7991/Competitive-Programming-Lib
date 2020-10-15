#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int n,k,*arr;
bool isSubSet()
{
  bool **dp=new bool*[2];
  dp[0]=new bool[k+1];
  dp[1]=new bool[k+1];
  fon(i,k+1) dp[0][i]=false;
  dp[0][0]=true;
  int flag=1;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=k;j++)
    {
      dp[flag][j]=dp[flag^1][j];
      if(j>=arr[i-1]) dp[flag][j]=dp[flag][j] || dp[flag^1][j-arr[i-1]];
    }
    flag^=1;
  }
  bool ans=dp[flag^1][k];
  delete []dp[0];delete []dp[1];
  return ans;
}
int main()
{
  cin>>n;
  arr=new int[n];
  fon(i,n)cin>>arr[i];
  cin>>k;
  bool ans=isSubSet();
  if(ans) cout<<"Yes";
  else cout<<"No";
  return 0;
}
