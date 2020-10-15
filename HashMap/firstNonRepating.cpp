#include <iostream>
#include <unordered_map>
#include <cstring>
#define um unordered_map
using namespace std;
char nonRepeatingCharacter(string str){
  
  um<char , int>freq;
  for(unsigned int i=0  ; i<str.length()  ;i++)
  {
  	freq[str[i]]++;
  }
  for (unsigned int i = 0; i < str.length(); ++i)
  {
  	if (freq[str[i]]==1)
  	{
  		return str[i];
  	}
  }
  return str[0];
}
int main()
{
	string str;
	cin>>str;
	cout<<nonRepeatingCharacter(str);
}