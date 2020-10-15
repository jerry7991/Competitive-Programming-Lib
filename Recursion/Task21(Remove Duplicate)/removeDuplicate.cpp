#include <iostream>
#include<cstring>
using namespace std;
string removeDuplicate(string str ,int start)
{
	if(str[start]=='\0')
		return str;
	char ch=str[start];
	unsigned int i;
	for ( i = start+1; i < str.length(); ++i)
	{
		if(ch==str[i])
			{
				unsigned int k=i+1;
				while( k<str.length())
				{
					if(str[k]==ch)
					{
						k++;
					}else{
						str[i++]=str[k++];
					}
				}
				str[i]='\0';
			}
	}
	return removeDuplicate(str , start+1);
}
int main()
{
	string str;
	cin>>str;
	cout<<removeDuplicate(str,0);
	return 0;
}