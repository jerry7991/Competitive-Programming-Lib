#include<iostream>
#include<cstring>
using namespace std;
int smallestSuperSequence(char str1[] ,int len1, char * str2 , int len2)
{
	if(len1==0 && len2==0)	return 0;
	if(len1==0)	return len2;
	if(len2==0)	return len1;
	int ans=0;
	if(str1[0]==str2[0]){
		ans=1+smallestSuperSequence(str1+1 , len1-1 , str2+1 , len2-1);
	}else{
		int opt1=1+smallestSuperSequence(str1+1, len1-1 , str2 , len2);
		int opt2=1+smallestSuperSequence(str1  , len1 , str2+1 ,len2-1);
		ans=min(opt1 , opt2);
	}
	return ans;
}
int main()
{
    char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequence(str1, len1, str2, len2);
    cout<<min_len;
    return 0;
}
