#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string s){
   if(s.size()==0 || s.size()==1)  return s;
   string output;
   for(int i=0 ; i<s.size() ; i++){
   	//for odd length
   	cout<<output<<'\n';
   	int left=i-1,right=i+1;
   	while(left>=0 && right<s.size() && s[left]==s[right]){
   		left--;right++;
   	}
   	left++;right--;
   	if(left>=0 && right<s.size() && output.size()<(right-left+1)){
   		output=s.substr(left , right-left+1);
   	}
   	//for even length
   	if(s[i]==s[i+1]){
   		left=i-1 , right=i+2;
   		while(left>=0 && right<=s.size() && s[left]==s[right]) {
   			left--;
   			right++;
   		}
   		left++;right--;
   	if(left>=0 && right<s.size() && output.size()<(right-left+1)){
   		output=s.substr(left , right-left+1);
   	 }
   	}
   }
   return output;
}
int main(){
	string str;
	cin>>str;
	cout<<longestPalindrome(str)<<'\n';
}