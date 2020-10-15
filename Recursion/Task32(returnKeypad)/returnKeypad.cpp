#include<bits/stdc++.h>
using namespace std;
int keypad(int num, string output[])
{
    //base case:
    if(num==0)
    {
        *(output)="";
        return 1;
    }
    int smallNum=num%10;
    int smallOutputSize=keypad(num/10 , output);
    string input[10]= {"", "", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};
    string inputString= *(input+smallNum);
    int k=0;
    string *copyOutput=new string[smallOutputSize];
    for(int i=0; i<smallOutputSize ;i++)
    {
        *(copyOutput+i)=*(output+i);
    }
    for(int i=0 ; i<inputString.size();i++)
    {
        int ci=0;
        for(; k<(i+1)*smallOutputSize; k++)
        {
            output[k]=copyOutput[ci++]+inputString[i];
        }
    }
   return inputString.size()*smallOutputSize;
}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
