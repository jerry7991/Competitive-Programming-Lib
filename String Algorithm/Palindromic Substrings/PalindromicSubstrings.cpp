#include <iostream>
#include<cstring>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int countPalindromeSubstrings(char s[])
{
	int n=strlen(s);
	int possibleLen=0;
	fon(i , n)
	{
		//for odd length of palindrom
		int left=i , right=i;//right==lef==i initially because each single char is palindrom
		while(left>=0 && right<n && s[left]==s[right]) possibleLen++,right++,left--;
		//for even length just right to current charcater
		if (i<n && s[i]==s[i+1])
		{
			left=i+2;right=i-1;//cause we have done with character itself
			while(left>=0 && right<n && s[left]==s[right]) possibleLen++,right++,left--;
		}
		//for even length just left to current charcater
		if (i>0 && s[i]==s[i-1])
		{
			left=i-2;right=i+1;
			while(left>=0 && right<n && s[left]==s[right]) possibleLen++,right++,left--;
		}
	}
	return possibleLen;
}
int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}
