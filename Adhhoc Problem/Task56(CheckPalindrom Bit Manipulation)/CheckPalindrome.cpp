#include<iostream>
#include<vector>
using namespace std;
vector<int>binary;
void getBinary(long number )
{
    if(number ==1)
    {
        //cout<<number;
        binary.push_back(number);
        return;
    }
    if(number ==0 )
    {
        //cout<<number<<endl;
        binary.push_back(number);
        return;
    }
    int rem=number%2;
    getBinary(number/2);
    //cout<<rem;
    binary.push_back(rem);
}
bool isPalindrome()
{
    int len=binary.size();
    for(int i=0  ; i<len ; i++,len--)
    {
        if(binary[i]!=binary[len-1])
        {
            return false;
        }
    }
    return true;
}
bool checkPalindrome(long number)
{
    getBinary(number);
    for(int i=0 ; i<binary.size() ; i++)
    {
        cout<<binary[i]<<"\t";
    }
    return isPalindrome();
}
int main()
{
    long number;
    cin>>number;
    if(checkPalindrome(number) )
    {
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}
