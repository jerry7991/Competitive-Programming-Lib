#include <iostream>
#define fon(i,n) for(int i=0 ; i<n  ; i++)
using namespace std;
int n , k;
int getAnswer(int *cost , int *fun , int st=0 , int x=k)
{
  if(n==st || x<=0)  return 0;
  int opt1=0,opt2=0;
  if(x>=cost[st])
  {
    opt1=fun[st]+getAnswer(cost , fun , st+1,x-cost[st]);
  }
  opt2=getAnswer(cost, fun , st+1,x);
  return max(opt1, opt2);
}
void solve()
{
  int *cost=new int[n];
  int *fun=new int[n];
  fon(i,n) cin>>cost[i]>>fun[i];
  cout<<getAnswer(cost , fun);
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
