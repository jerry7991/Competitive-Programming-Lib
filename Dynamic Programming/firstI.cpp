#include<iostream>
#include<string>
#define mod 1000000007
using namespace std;
inline int getIntVal(char ch)
{
  return (ch-'0');
}
int getTotalPossibleCode(string input,int len , int*dp)
{
  if (len==0) {
    return 1;
  }
  if (len==1) {
    if (input[len-1]!='0') {
      return 1;
    }
    return 0;
  }
  long ans=0;
  int curr=getIntVal(input[len-1]);
  if (curr>0 && curr<27) {
    ans=(ans+getTotalPossibleCode(input , len-1 , dp))%mod;
  }
  int next=getIntVal(input[len-2])*10+curr;
  if (next>0 && next<27) {
    ans=(ans+getTotalPossibleCode(input , len-2 , dp))%mod;
  }
  return ans;
}
int solve(string input )
{
  int n=input.size();
  int *dp=new int[n+1];
  for (size_t i = 0; i <=n; i++) {
    dp[i]=-1;
  }
  int ans=getTotalPossibleCode(input,n,dp);
  delete []dp;
  return ans;
}
int main()
{
  while(1)
  {
    string input;
    cin>>input;
    if (input.size()==1 && input[0]=='0') {
      return 0;
    }
    cout<<solve(input)<<endl;
  }
}
