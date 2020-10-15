#include<iostream>
using namespace std;
void print_subString(string input , string output)
{
    if(input.length()==0)
    {
        cout<<output<<endl;
        return;
    }
    //let's ignore first character
    print_subString(input.substr(1) , output);
    //let's include first character in output
    print_subString(input.substr(1) , output+input[0]);
}
int main()
{
    string input;
    cin>>input;
    string output="";
    print_subString(input , output);
}
