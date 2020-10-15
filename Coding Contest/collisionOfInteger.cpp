#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;
void solve(ull n , ull m)
{
  vector<int>nDigit;
  vector<int>mDigit;
  vector<int> ans;
  int nfalls=0,mfalls=0;
  while(n)
  {
    nDigit.push_back(n%10);
    n/=10;
  }
  while(m)
  {
    mDigit.push_back(m%10);
    m/=10;
  }
  reverse(nDigit.begin() , nDigit.end());
  reverse(mDigit.begin() , mDigit.end());
  int nEnd=nDigit.size()-1,mEnd=mDigit.size()-1;
  while (nEnd>=0 && mEnd>=0) {
    if(nDigit[nEnd]==mDigit[mEnd])  continue;
    if(nDigit[nEnd]>mDigit[mEnd]){
      mfalls++;
      mDigit[mEnd]=0;
    }else{
      nDigit[nEnd]=0;
      nfalls++;
    }
    nEnd--;mEnd--;
  }
  if(nfalls==nDigit.size())
  {
    cout<<"YODA"<<endl;
  }else{
    ull ans=0;
    for(int i=0;i<nDigit.size() ; i++)
    {
      ans=ans*10+nDigit[i];
    }
    cout<<ans<<endl;
  }
  if(mfalls==mDigit.size())
  {
      cout<<"YODA"<<endl;
  }else
    {
    ull ans=0;
    for(int i=0 ; i<mDigit.size() ; i++)
    {
      ans=ans*10+mDigit[i];
    }
    cout<<ans<<endl;
  }
}
int main()
{
  ull n,m;
  cin>>n>>m;
  solve(n,m);
  return 0;
}
