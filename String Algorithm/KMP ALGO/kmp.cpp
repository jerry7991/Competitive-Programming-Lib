#include <iostream>
#include <cstring>
using namespace std;
void getLps(string text ,int* lps)
{
	int len=text.length();
	int i=1;
	int j=0;
	lps[0]=0;
	while(i<len)
	{
		if (text[i]==text[j])
		{
			lps[i++]=++j;
		}else{
			if (j==0)
			{
				lps[i++]=0;
			}else{
				j=lps[j-1];
			}
		}
	}
}
bool KMP(string text , string pattern)
{
	int lenText=text.length();
	int lenPattern=pattern.length();
	int *lps=new int[lenText];
	getLps(text , lps);
	int j=0 , i=0;
	while(i<lenText && j<lenPattern)
	{
		if (text[i]==pattern[j])
		{
			i++;j++;
		}else{
			if(j==0)
			{
				i++;
			}else{
				j=lps[j-1];
			}
		}
	}
	if (j==lenPattern)
	{
		return true;
	}
	return false;
}
int main()
{
	string text,pattern;
	cin>>text;
	cin>>pattern;
	bool answer=KMP(text , pattern);
	if (answer)
	{
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}