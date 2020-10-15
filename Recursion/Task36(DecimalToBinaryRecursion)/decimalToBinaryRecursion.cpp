#include<iostream>
using namespace std;
void convertBinary(int number)
{
    if(number==0)
        return ;
    int remainder=number%2;
    convertBinary(number/2);
    cout<<remainder<<"\t";
}
int main()
{
    int number;
    cin>>number;
    convertBinary(number);
    return 0;
}
