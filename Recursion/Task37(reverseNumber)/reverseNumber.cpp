#include<iostream>
using namespace std;
int reverseNumber(int num)
{

int sum=0;
    while(num>0)
    {
        sum=sum*10+(num%10);
        num =num/10;
    }
    return sum;
}
int main()
{
    int number;
    cin>>number;
    number=reverseNumber(number);
    cout<<number;
    return 0;
}
