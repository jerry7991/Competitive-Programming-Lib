#include <iostream>
using namespace std;
inline bool isPalindrom(string str){
	int i=0 , j=str.size()-1;
	while(i<j)		if(str[i++]!=str[j--]) return false;
	return true;
}
int longestPalindromeSubseq(string input , string currStr="" ,unsigned int len=0){
	if(len==input.size()) return currStr.size()*isPalindrom(currStr);
	int exclude=longestPalindromeSubseq(input , currStr , len+1);
	string curr=currStr+input[len];
	int include=longestPalindromeSubseq(input , curr , len+1);
	return max(exclude , include);
}
int main(){
	string str;
	cin>>str;
	cout<<longestPalindromeSubseq(str);
}