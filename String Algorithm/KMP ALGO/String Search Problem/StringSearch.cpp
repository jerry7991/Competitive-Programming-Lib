#include <iostream>
#include<cstring>
#include <vector>
#define pb(n) push_back(n)
using namespace std;
void filLps(string text , int * lps)
{
	int len=text.length();
	int i=1,j=0;
	lps[0]=0;
	while(i<len)
	{
		if (text[i]==text[j])
		{
			lps[i]=j+1;
			i++;j++;
		}else{
			if (j==0)
			{
				//we cann't do much more
				lps[i++]=0;
			}else{
				j=lps[j-1];
			}
		}
	}
}
void getIndex(string text ,string pattern ,vector<int> & index)
{
	int lenText=text.length();
	int lenPattern=pattern.length();
	//go fill lps first
	int * lps=new int[lenText];
	filLps(text , lps);
	int t=0,p=0;
	while(t<lenText )
	{ 
		if (text[t]==pattern[p])
		{
			t++;p++;
			if (p==lenPattern)
			{
				index.pb(t-p);
				p=lps[p-1];
			}
		}else{
			if (p==0)
			{
				t++;
			}else{
				p=lps[p-1];
			}
		}
	}
}
int main()
{
	string text,pattern;
	getline(cin , text);
	getline(cin , pattern);
	//cin>>text;
	//cin>>pattern;
	vector<int> index;
	getIndex(text , pattern , index);
	if(index.size()==0)
	{
		cout<<-1;
	}else{
		for (int i = 0; i < index.size(); ++i)
		{
			cout<<index[i]<<" ";
		}
	}
}
/*
#include<string.h>
using namespace std;
int findString(char S[], char T[]) 
{
  int len1=strlen(S)+1;
int len2=strlen(T)+1;
    int i=0,j;
    while(i<len1){
        if(S[i]==T[0]){
             j=i;
            while(j<len1 && (j-i)<len2 && S[j]==T[j-i]) j++;
            if(T[j-i]=='\0') 
                return i;
        }
        i++;
    }
    return -1;
}
*/