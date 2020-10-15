#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1024
int getNShortestSubsequence(char *str1 ,int len1 ,char * str2 ,int len2)
{
	if(len1==0)
		return MAX;
	if(len2<=0)
		return 1;
	int x;        
	for (x = 0; x <len2; ++x)
	{
		if(str2[x]==str1[0])
			break;
	}
	if(x==len2)
		return 1;
	//let's skip 1'st element of str1
	int option1=getNShortestSubsequence(str1+1 , len1-1 ,str2 , len2);
	//let's include to 1'st element of str2
	int option2=1+getNShortestSubsequence(str1+1 , len1-1 , str2+x+1 , len2-x-1);
	return min(option1,option2);
}
int main()
{
	char *str1=new char[1028];
	char *str2=new char[1028];
	cin>>str1>>str2;
	int len1=strlen(str1);
	int len2=strlen(str2);
	cout<<getNShortestSubsequence(str1 , len1 , str2 , len2);
}