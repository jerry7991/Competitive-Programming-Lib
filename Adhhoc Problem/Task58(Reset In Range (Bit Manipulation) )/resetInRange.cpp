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
    long number ;
    int haveToLeftShift , haveToRightShift;
    cin>>number>>haveToLeftShift>>haveToRightShift;

    //first set total as one
    long allOnce=~0;
    //first reach at the left-th position
    int leftShift= allOnce << (haveToLeftShift) ; //it gives if haveToLeftShift=4 then left =1 1 1 0 0 0 0
        //cout<<"\n left shift \n";
        //convertBinary(leftShift);

    //make space for right shift

     int rightShift = ((1<<haveToRightShift-1)-1);  //now it becomes if haveToRightShift =3 ; leftShift=11
        //cout<<"\nright shift\n";
        //convertBinary(rightShift);
     int mask= leftShift | rightShift; ////now it becomes mask=1 1 10 011
     //cout<<"\n mask"<<endl;
     //convertBinary(mask);

     //now make and with given number
     number = number & mask;
     //it becomes:-
     /*
     if num=63;
        num       = 0 1 1 1 1 1 1
       &
        mask =      1 1 1 0 0 1 1
        ----------------------------------
        leftShift = 0 1 1 0 0 1 1 =51
        ----------------------------------
     */
     cout<<endl;
     convertBinary(number);
     cout<<number;
     return 0;
}
