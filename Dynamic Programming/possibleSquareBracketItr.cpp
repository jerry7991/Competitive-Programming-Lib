#include <iostream>
#define cin(x) int x;cin>>x;
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
void countPossibleBracket()
{
  cin(n);cin(k);
  bool *memo=new bool[2*k+1];
  fon(i,2*k+1) memo[i]=false;
  fon(i , k){
    cin(x);
    memo[x]=true;
  }
  if(memo[0]) return;
  int **dp=new int*[n+1];
  fon(i,n+1) dp[i]=new int[n+1];
  //base case
  dp[n][n]=1;
  for(int i=n-1 ; i>=0;i--)dp[n][i]=dp[i][n]=dp[n][i+1];
  for(int open=n-1 ; open>=0 ; open--)//for opening
  {
    for(int close=n-1 ; close>=0 ; close--)//for closing
    {
      if(open==close || memo[open+close]) dp[open][close]=dp[open+1][close];
      else if(open==0) dp[open][close]=dp[open][close+1];
      else{
        dp[open][close]=(dp[open][close+1]+dp[open+1][close]);
      }
    }
  }
  fon(i,n+1)
    {
      fon(j , n+1) cout<<dp[i][j]<<" ";
      cout<<endl;
    }
}
int main()
{
  cin(t);
  while (t--) {
    countPossibleBracket();
  }
}
