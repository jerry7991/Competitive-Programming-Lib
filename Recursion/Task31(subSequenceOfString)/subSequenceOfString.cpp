#include<bits/stdc++.h>
using namespace std;
int substring(string input , string output[])
{
    //base case:=
    if(input.empty())
    {
        output[0]="";
        return 1;
    }
    string smallString=input.substr(1);
    int smallOutputSize=substring(smallString , output);

    //for each subsequence we have to merge input[0]
    for(int i=0;i<smallOutputSize;i++)
    {
        output[i+smallOutputSize]=input[0]+output[i];
    }
    return 2*smallOutputSize;
}
int main()
{
    string input;
    cin>>input;
    int len=input.size();
    len=pow(2,len);
    string * output=new string[1000];
    int count=substring(input , output);
    for(int i=0; i <count;i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}
