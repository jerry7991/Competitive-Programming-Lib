#include <iostream>
#include <vector>
#define pb(n) push_back(n)
using namespace std;
int lengthOfLIS(vector<int>& nums)
{
  int n=nums.size();
  int *lis=new int[n];
  for(int i=0;i<n ; i++)  lis[i]=0;
  lis[0]=1;
  for(int i=1;i<n ; i++)
  {
    lis[i]=1;
    for(int j=i-1;j>=0;j--)
    {
      if(nums[j]>=nums[i])
        continue;
      int possAns=lis[j]+1;
      if(possAns>lis[i])
      {
        lis[i]=possAns;
      }
    }
  }
  int maxVal=0;
  for(int i=0 ; i<n ; i++)
    maxVal=max(lis[i] , maxVal);
  return maxVal;
}
int main()
{
  int n;
  cin>>n;
  vector<int> v;
  for(int i=0 ; i<n;i++)
  {
    int x;
    cin>>x;
    v.pb(x);
  }
  cout<<lengthOfLIS(v)<<endl;
  return 0;
}
