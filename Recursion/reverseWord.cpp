#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
      if(s.size()==0) return s;
        stack<string> str;
      string output;
      for(int i=0 ; i<s.size() ; i++){
        if(s[i]==' '  && output.size()){
          str.push(output);
          string n;
          output=n;
          continue;
        }else if(s[i]==' ') continue;
        output=output+s[i];
      }
      if(output.size()) str.push(output);
      string ans;
      if(str.size()==0)
         return ans;
      ans=str.top();
      str.pop();
      while(str.size()){
        ans=ans+" "+str.top();
        str.pop();
      }
      return ans;
    }
};
int main(){
	string str;
	cin>>str;
	cout<<ans(str);
}