#include <iostream>
#define mod 1000000007
using namespace std;
int countBst(int n)
{
  if(n==0 || n==1)
  {
    return 1;
  }
  int ans=0;
  for(int i=1 ; i<=n ; i++)
  {
    ans+=countBST(i-1)*countBST(n-i);
  }
  return ans;
}
int countBST(int n)
{
  int *dp=new int[n+1];
dp[0]=dp[1]=1;
for(int i=2 ; i<=n;i++)
{
 dp[i]=0;
 for(int j=1 ; j<=i ; j++)
 {
   long ans=((long)dp[j-1]%mod*dp[i-j]%mod)%mod;
    int ans1=(int)(ans%mod);
   dp[i]=(dp[i]+ans1)%mod;
 }
}
return dp[n];
}
int main()
{
  int n;
  cin>>n;
  cout<<countBST(n)<<endl;
  return 0;
}
