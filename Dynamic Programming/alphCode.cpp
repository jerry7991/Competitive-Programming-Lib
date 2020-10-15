#include <iostream>
#include <string>
using namespace std;
int getTotalPossibleCode(string str , int start)
{
  if (str[start]=='\0') {
    return 0;
  }
  //there would be total two option
  int ans=0;
  if ((str[start]-'0')>0 && (str[start]-'0')<27) {
    ans+=1+getTotalPossibleCode(str , start+1);
  }
  if( str[1]!='\0' ((str[start]-'0')*10+str[start+1])>0 && ((str[start]-'0')*10+str[start+1])<27)
  {
    ans+=1+getTotalPossibleCode(str , start+2);
  }
  return ans;
}
int main()
{
  while (true) {
    std::string str;
    cin>>str;
    if(str.size()==1 && str[]=='0')
    {
      return 0;
    }
    std::cout << getTotalPossibleCode(str,0) << '\n';
  }
}
