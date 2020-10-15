#include <iostream>
#include <cstring>
#define fon(i , n) for(int i=0 ; i<n ; i++)
using namespace std;
void getLps(int *lps , string str)
{
	int len=str.length();
	int i=1,j=0;
	lps[0]=0;
	while(i<len)
	{
		if(str[i]==str[j])
		{
			lps[i]=j+1;
			i++;j++;
		}else{
			if(j==0)
			{
				//we cann't do any more
				lps[i]=0;
				i++;
			}else{
				j=lps[j-1];
			}
		}
	}
}
int main()
{
	string str;
	cin>>str;
	int *lps=new int[str.length()];
	getLps(lps , str);
	fon(i , str.length())
	{
		cout<<lps[i]<<" ";
	}
	delete []lps;
}