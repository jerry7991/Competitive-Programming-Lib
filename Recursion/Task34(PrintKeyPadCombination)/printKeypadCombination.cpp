#include<iostream>
using namespace std;
void printKeypadCombinatoin(int num , string output)
{
    //base case
    if(num==0)
    {
        cout<<output<<endl;
        return;
    }
    int smallNum=num%10;
    string input[10]= {"", "", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};
    string inputString= *(input+smallNum);
    for(int i=0;i<inputString.size();i++)
    {
        //ignore first  element
        printKeypadCombinatoin(num/10 , inputString[i]+output);
    }
}
void printKeypad(int num)
{
    string output="";
    printKeypadCombinatoin(num,output);
}
int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

