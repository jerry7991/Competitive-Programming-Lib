
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

    long range= ((1L <<(haveToRightShift-1))-1 ^ ((1L << haveToLeftShift)-1));
    range = ~ range;
    cout<< (number & range);
     return 0;
}
