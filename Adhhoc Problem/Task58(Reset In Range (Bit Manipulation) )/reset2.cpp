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
    int number ;
    int haveToLeftShift , haveToRightShift;
    cin>>number>>haveToLeftShift>>haveToRightShift;

    int allOnes=~0;

    int left=allOnes << (haveToLeftShift);
    int right=((1 <<haveToRightShift-1) -1);
    int mask= left | right;
    number=number & mask;
    cout<<number<<endl;
    convertBinary(number);
     return 0;
}
