#include<bits/stdc++.h>
using namespace std;
int counts(string input){
    int len=input.size();
    int count=0;
    //for odd length
    for(int i=0;i<len;i++){
        int mid=i;
        int left=i-1;
        int right=i+1;
        count++;
        while(left>=0 && right<len && input[left]==input[right]){
            count=count+1;
           // cout<<count<<endl;
            left--;
            right++;
        }
        //for even length
        if(i<len-1 && input[i]==input[i+1]){
            left=i-1;
            right=i+2;
            count++;
            while(left>=0 && right<len && input[left]==input[right]){
            count=count+1;
            left--;
            right++;
        }
    }
    }
    return count;
}
int countPalindromeSubstrings(char s[]) {
    // Write your code here
    string input="";
    for(int i=0;s[i]!='\0';i++){
        input=input+s[i];
    }  
    int ans=counts(input);
    return ans;
}
/**
#include<bits/stdc++.h>
using namespace std;
int count(string input){
    int len=input.size();
    int count=0;
    //for odd length
    for(int i=0;i<len;i++){
        int mid=i;
        int left=i-1;
        int right=i+1;
        while(left>0 && right<len && input[left]==input[right]){
            count=count+1;
           // cout<<count<<endl;
            left--;
            right++;
        }
        count=count+1;
    }
    //for even lengt
    for(int i=0;i<len;i++){
        int mid=i;
        int mid1=i+1;
        int left=mid-1;
        int right=mid1+1;
        while(left>0 && right<len && input[left]==input[right]){
            count=count+1;
            left--;
            right++;
        }
      //  count=count+1;
    }
    return count;
}
int countPalindromeSubstrings(char s[]) {
    // Write your code here
    string input="";
    for(int i=0;s[i]!='\0';i++){
        input=input+s[i];
    }
  int ans=count(input);
    return ans;
}