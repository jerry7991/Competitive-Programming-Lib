#include <iostream>
#include <string>
#include<unordered_set>
using namespace std;
unordered_set<string> subSeq;
void countDistinctSubSeq(string str ,int start , int len , string output="")
{
  if(start==len)
  {
    subSeq.insert(output);
    return;
  }
  string temp=output+str[start];
  countDistinctSubSeq(str , start+1 , len , temp);
  countDistinctSubSeq(str , start+1 , len , output);
}
int main()
{
  string str1;
  cin>>str1;
  countDistinctSubSeq(str1 , 0 , str1.size());
  cout<<subSeq.size()<<endl;
}
