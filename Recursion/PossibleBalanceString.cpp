#include <iostream>
#include <queue>
#include<string>
#include <stack>
#include<map>
using namespace std;
bool isBalanced(string str)
{
  int diffOpeClose=0;
  for(int i=0 ; i<str.size() ; i++)
  {
    if(str[i]=='(')
      diffOpeClose++;
    else
      diffOpeClose--;
    if(diffOpeClose<0)
      return false;
  }
  return (diffOpeClose==0);
}
void removeInvalidParentheses(string str)
{
  //let's first find the number of those char which make string unbalanced
  bool isBal=isBalanced(str);
  if(isBal)
  {
    cout<<str<<endl;
    return;
  }
  stack<string> output;
  queue<string> bfs;
  bfs.push(str);
  map<string , int> visited;
    bool found=false;
  while(bfs.size())
  {
    string st=bfs.front();
    bfs.pop();
    if(isBalanced(st))
    {
      //cout<<st<<endl;
      output.push(st);
        found=true;
      continue;
    }
    if(found)  //i.e. level has ended now;; we wouldn't add more
      continue;
    for(int i=0 ; i<st.size() ;i++)
    {
      //we can remove all the char one by one
      string s=st.substr(0,i)+st.substr(i+1,st.size());
      if(!visited[s])
      {
          bfs.push(s);
          //mark s as visited;
          visited[s]++;
      }
    }
  }
  while (output.size()) {
    cout<<output.top()<<endl;
    output.pop();
  }
}
int main()
{
  string input;
  cin>>input;
  removeInvalidParentheses(input);
  return 0;
}
