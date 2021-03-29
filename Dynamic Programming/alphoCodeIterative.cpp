#include <iostream>
#include <string>
#define mod 1000000007
using namespace std;
int getTotalPossibleCode(string str)
{
  int n=str.length();
  int *dp=new int[n+1];
  for (size_t i = 0; i < n+1; i++) {
    dp[i]=0;
  }
  dp[0]=1;//by default 1 string possible that will be null
  for(int i=1;i<=n ; i++)
  {
    int x=(str[i-1]-'0')*10+(str[i]-'0');
    if(str[i]!='0')
      dp[i]=dp[i-1];
    if(x>=10 && x<=26 && i>1) 
      dp[i]+=dp[i-2];
    else if(x>=10 && x<=26)
      dp[i]++;

    dp[i]%=mod;
  }
  return dp[n-1];
}
int main()
{
 string str;

 while (1) {
   std::cin >> str;
   if(str[0]=='0')
    return 0;
   std::cout << getTotalPossibleCode(str) << '\n';
 }
}
