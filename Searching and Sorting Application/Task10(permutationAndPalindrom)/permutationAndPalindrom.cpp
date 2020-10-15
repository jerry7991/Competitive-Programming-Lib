#include<bits/stdc++.h>
using namespace std;
char getChar(int i)
{
    return (char)(i+97);
}



void printPalindromeString(string str)
{
    map<char ,vector<int> > indexMap;

    //let's store index of each character
    for(int i=0 ; i<str.size(); i++)
    {
        indexMap[str[i]].push_back(i);
    }

    //let's check violation of palindrome i.e. if total number of (odd number of character) is greater than 1 then we can't make palindrome
    int odd_frequency=0;
    for(int i=0;i<26;i++)
    {
        int currentChar=getChar(i);
        if(indexMap[currentChar].size() % 2!=0)
        {
            odd_frequency++;
        }
    }
    //if condition violate then print -1 and return
    if(odd_frequency>=2)
    {
        cout <<-1;
        return;
    }
    //else we have to check for palindrome
    int startIndex=0,lastIndex=str.length()-1;
    int ans[str.length()];
    for(int i=0;i<26;i++)
    {
        char currentChar=getChar(i);
        for(int j=0 ; j<indexMap[currentChar].size(); j+=2)
        {
            //check for single odd character
            if((indexMap[currentChar].size()-j)==1)     //means single character left so we will have to store it in the middle
            {
                ans[str.length()/2]=indexMap[currentChar][j];
                continue;
            }
            ans[startIndex]=indexMap[currentChar][j];
            ans[lastIndex]=indexMap[currentChar][j+1];
            startIndex++;
            lastIndex--;
        }
    }
        for(int i=0;i<str.length();i++)
        {
            cout <<ans[i]+1<<" ";
        }
        return;
}
int main()
{
    int textCases;
    cin>>textCases;
    while(textCases--)
    {
        string str;
        cin >>str;
        printPalindromeString(str);
        cout<<endl;
    }
    return 0;
}
