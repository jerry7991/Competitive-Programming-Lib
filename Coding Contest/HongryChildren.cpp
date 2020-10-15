#include <bits/stdc++.h>
using namespace std;
int findMax(map<string , int> m, string str)
{
  map<string ,int> :: iterator itr=m.begin();
  int currMax=0;
  while(itr!=m.end())
  {
    string s=itr->first;
    int i=0;
    for(i=0 ;i<str.length()&& i<s.length();i++ )  if(s[i]!=str[i]) break;
    if(i==s.length() || i==str.length())  continue;
    currMax=max(currMax , itr->second);
    itr++;
  }
  return currMax;
}
int main()
{
  int n;
  cin>>n;
  map<string , int> freq;
  int currMax=0,scolds=0;
  while(n--)
  {
    string ch;
    cin>>ch;
    int x=findMax(freq , ch);
    if(freq[ch]>x)
    {
      scolds++;
    }
    freq[ch]++;
  }
  cout<<scolds;
}
