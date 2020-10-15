#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int **cost,n;
int getMinCost(int a , int c, int curr)
{
  int ans=0;
  if(a==n/2)
  {
   ans=0;int x=curr;
    while(x<n){
      ans+=cost[0][x++];
    }
  }else if(a==c)
  {
    //we can make only assistance
    ans=cost[1][curr]+getMinCost(a+1,c,curr+1);
  }else if(a>c){
    int opt1=cost[0][curr]+getMinCost(a,c+1,curr+1);
    int opt2=cost[1][curr]+getMinCost(a+1 , c , curr+1);
    ans=min(opt1,opt2);
  }
  return ans;
}
int main()
{
  cin>>n;
  cost=new int*[2];
  cost[0]=new int[n];
  cost[1]=new int[n];
  fon(i,n)
  {
    cin>>cost[0][i];
    cin>>cost[1][i];
  }
  cout<<getMinCost(0,0,0);
}
