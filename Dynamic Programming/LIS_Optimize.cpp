#include <bits/stdc++.h>
using namespace std;
 int lengthOfLIS(vector<int>& nums)
 {
   vector<int> v;
   vector<int> :: iterator it;
       int n = nums.size();

       for(int i = 0;i<n;i++){

            it = lower_bound(v.begin(),v.end(),nums[i]);
           if(it==v.end()){
               v.push_back(nums[i]);
           }
           else{
               *it = nums[i];
           }
       }
       return v.size();
 }
int main()
{
  int n;
  cin>>n;
  vector<int> v;
  for (size_t i = 0; i < n; i++) {
    int x;
    cin>>x;
    v.push_back(x);
  }
  cout<<lengthOfLIS(v);
}
