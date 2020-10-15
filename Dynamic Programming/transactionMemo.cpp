#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int n,k,*price;
int getMaxProfit(int ***dp , int start=0 , int nTransaction=0 , int onGoing=0)
{
  if(start==n || nTransaction==k)  return 0;
  //we have allready ans
  if(dp[start][nTransaction][onGoing]!=-1)  return dp[start][nTransaction][onGoing];
  //one possibility is always available.. ingore the current stock transaction
  int ingore=getMaxProfit(dp , start+1, nTransaction , onGoing);
  if(onGoing){
    //can only sell
    int sell=getMaxProfit(dp , start+1, nTransaction+1 , 0)+price[start];
    ingore=max(sell , ingore);
  }else{
    if(nTransaction<k){
      int buy=getMaxProfit(dp,start+1 , nTransaction , 1)-price[start];
      ingore=max(buy  , ingore);
    }else{
      ingore=0;
    }
  }
  return dp[start][nTransaction][onGoing]=ingore;
}
int main()
{
  int t;
  cin>>t;
  while (t--) {
    cin>>k>>n;
    price=new int[n];
    fon(i,n) cin>>price[i];
    //there will be three variable 1.remaining days for stock,2.number of transaction ,3.onGoing transaction
    int ***dp=new int**[n+1];
    fon(i,n+1){
      dp[i]=new int*[k+1];
      fon(j,k+1){
        dp[i][j]=new int[2];
        dp[i][j][0]=-1;
        dp[i][j][1]=-1;
      }
    }
    cout<<getMaxProfit(dp)<<endl;
    //release memory
    delete []price;
    fon(i,n+1){
      fon(j,k+1)
        delete []dp[i][j];
      delete [] dp[i];
      }
    delete []dp;
  }
}
