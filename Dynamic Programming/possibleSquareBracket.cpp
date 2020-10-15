#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
bool *reqOpen;
int n,k,**dp;
int countPossibleBracket(int open , int close)
{
  //base case:-
  if(open>n || close>n)return 0;
  if(open==n && close==n) return 1;//one possible
  if(dp[open][close]!=-1) return dp[open][close];
  //condition for only opening bracket
  int ans=0;
  if(open==close || reqOpen[open+close+1])
  {
    ans=countPossibleBracket(open+1 , close);
  }else if(open==n){
    //only closing bracket will possible
    ans=countPossibleBracket(open , close+1);
  }else{
    //both opening and closing bracket will possible
    int opt1=countPossibleBracket(open+1 , close);
    int opt2=countPossibleBracket(open  , close+1);
    ans=(opt1+opt2);
  }
  return dp[open][close]=ans;
}
void solve()
{
  cin>>n>>k;
  reqOpen=new bool[2*n+1];
  fon(i,2*n+1) reqOpen[i]=false;
  fon(i,k){
    int x;
    cin>>x;reqOpen[x]=true;
  }
  dp=new int*[n+1];
  fon(i , n+1)
  {
    dp[i]=new int[n+1];
    fon(j,n+1)  dp[i][j]=-1;
  }
  if(!reqOpen[0])//because question has given range
    cout<<countPossibleBracket(0 , 0)<<endl;
  fon(i,n+1)
  {
    fon(j,n+1) cout<<dp[i][j]<<" ";
    cout<<endl;
  }
  delete []reqOpen;
  fon(i,n+1)  delete []dp[i];
  delete []dp;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
    solve();
}
