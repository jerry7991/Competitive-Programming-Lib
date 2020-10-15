#include<iostream>
#define mod 1000000007
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define cn currentBitCount
#define st start
using namespace std;
int dp[101][101][2];
int len,bitCount;
void init(){
  fon(i,101)
    fon(j,101)
      fon(k,2)  dp[i][j][k]=-1;
}
int solve(int st , int cn ,int preBit)
{
  if(st==len)
    return (bitCount==cn);
  int &ans=dp[st][cn][preBit];
  if(ans!=-1)  return ans;
  ans=solve(st+1 , cn+preBit , 1);
  ans+=solve(st+1 , cn , 0);
  ans%=mod;
  return ans;
}
int main()
{
  int t,sn;
  cin>>t;
  while (t--) {
    cin>>sn>>len>>bitCount;
    init();
    int ans=solve(0,0,0);
    cout<<sn<<" "<<ans<<endl;
  }
}
