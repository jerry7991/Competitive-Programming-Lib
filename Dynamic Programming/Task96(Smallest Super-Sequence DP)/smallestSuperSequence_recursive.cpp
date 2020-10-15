#include<iostream>
#include<cstring>
using namespace std;
int smallestSuperSequence(char str1[], int len1, char str2[], int len2) 
{
	if(len1==0 && len2!=0)
	{
		return len2;
	}else if(len1!=0 && len2==0)
	{
		return len1;
	}else if(len1==0 && len2==0)
	{
		return 0;
	}else{

		int answer;
		if(str1[0]==str2[0])
		{
			answer=1+smallestSuperSequence(str1+1 , len1-1 , str2+1 , len2-1);
		}else{
			//we have two choice either we can take first element of str1 into super sequence
			int option1=1+smallestSuperSequence(str1+1 , len1-1 , str2 , len2);
			//or take first element of str2 element into sequence
			int option2=1+smallestSuperSequence(str1 , len1 , str2+1 , len2-1);
			answer= (option1>option2)?option2:option1;
		}
		return answer;
	}
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
