#include <iostream>
#include <string>
#define mod 1000000007
using namespace std;
int subString(string str)
{
  long long totalSum = str[0] - '0';
  long long currSum = str[0] - '0';
  for (int i = 1 ; i < str.size() ; i++)
  {
    currSum = currSum * 10 + ((str[i] - '0') * (i + 1));
    currSum %= mod;
    totalSum = (currSum + totalSum) % mod;
  }
  return totalSum;
}
int main()
{
  std::string str;
  cin >> str;
  cout << subString(str);
}
