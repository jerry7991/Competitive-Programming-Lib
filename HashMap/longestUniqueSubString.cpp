#include <iostream>
#include <string>
#include <unordered_map>
#define um unordered_map
using namespace std;
int longestSubstr(string s)
{
	int startIndex=0;int start;
	int maxLen=0; unsigned i=0;
	um<char,int> m;
	for ( i = 0; i < s.length(); ++i)
	{
		if (m[s[i]]==0)
		{
			//i.e. unique character
			m[s[i]]=i;
		}else{
			//we got a duplicate element
			if (m[s[i]]>=startIndex)
			{
				//i.e. weather current duplicate element lies in uniques string
				int currLen=i-startIndex;
				if(currLen>maxLen)
                {
                    maxLen=currLen;
//                     start=startIndex;
                }
			//now we have to shift our starting point of uniques string for which avoid duplicate
			startIndex=m[s[i]]+1;
			}
			//now set current index to current char
			m[s[i]]=i;
		}
	}
	//check the end point of string
	if (maxLen<(i-startIndex))
	{
		maxLen=i-startIndex;
//         start=startIndex;
	}
	return maxLen;
}
int main()
{
	string str;
	cin>>str;
	cout<<longestSubstr(str);
	return 0;
}